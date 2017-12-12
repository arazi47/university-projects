import unittest
from controller import Controller
import datetime

class TestNewController(unittest.TestCase):
    def testClientFunctions(self):
        ctrl.addClient("name")
        self.assertEqual(ctrl.getClientIdByName("name"), 1)

        self.assertEqual(len(ctrl.getClients()), 1)

        ctrl.undo()
        self.assertEqual(len(ctrl.getClients()), 0)

        ctrl.redo()
        self.assertEqual(len(ctrl.getClients()), 1)

        ctrl.removeClient("name")
        self.assertEqual(len(ctrl.getClients()), 0)

        ctrl.undo()
        self.assertEqual(len(ctrl.getClients()), 1)


    def testMovieFunctions(self):
        ctrl.addMovie('t', 'd', 'g')
        self.assertEqual(len(ctrl.getMovies()), 1)

        ctrl.undo()
        self.assertEqual(len(ctrl.getMovies()), 0)

        ctrl.redo()
        self.assertEqual(len(ctrl.getMovies()), 1)

        ctrl.removeMovie('t')
        self.assertEqual(len(ctrl.getMovies()), 0)


    def testRental(self):
        ctrl.addClient("name")
        ctrl.addMovie('t', 'd', 'g')
        ctrl.addRental(1, 1, datetime.datetime.now())
        self.assertEqual(ctrl.getRentalByMovieId(1).getClientId(), 1)
        self.assertEqual(len(ctrl.getRentedMovies()), 1)

        ctrl.undo()
        self.assertEqual(len(ctrl.getRentedMovies()), 0)

        ctrl.redo()
        self.assertEqual(len(ctrl.getRentedMovies()), 1)

        #self.assertEqual(ctrl.getRentalByMovieId(1).getReturnedDate(), -1)
        ctrl.returnMovie(1, datetime.datetime.now())
        self.assertNotEqual(ctrl.getRentalByMovieId(1).getReturnedDate(), -1)

        ctrl.undo()
        #self.assertEqual(ctrl.getRentalByMovieId(1).getReturnedDate(), -1)
        ctrl.redo()
        self.assertNotEqual(ctrl.getRentalByMovieId(1).getReturnedDate(), -1)


    def runTests(self):
        self.testClientFunctions()
        #self.testMovieFunctions()
        #self.testRental()


# create a new controller for testing purposes
ctrl = Controller()