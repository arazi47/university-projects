import unittest
from controller import Controller
import datetime


class TestController(unittest.TestCase):
    def testClientFunctions(self):
        self.ctrl.addClient("name")
        self.assertEqual(self.ctrl.getClientIdByName("name"), 1)
        self.assertEqual(len(self.ctrl.getClients()), 1)

        self.ctrl.undo()
        self.assertEqual(len(self.ctrl.getClients()), 0)

        self.ctrl.redo()
        self.assertEqual(len(self.ctrl.getClients()), 1)

        self.ctrl.removeClient("name")
        self.assertEqual(len(self.ctrl.getClients()), 0)

        self.ctrl.undo()
        self.assertEqual(len(self.ctrl.getClients()), 1)


    def testMovieFunctions(self):
        self.ctrl.addMovie('t', 'd', 'g')
        self.assertEqual(len(self.ctrl.getMovies()), 1)

        self.ctrl.undo()
        self.assertEqual(len(self.ctrl.getMovies()), 0)

        self.ctrl.redo()
        self.assertEqual(len(self.ctrl.getMovies()), 1)

        self.ctrl.removeMovie('t')
        self.assertEqual(len(self.ctrl.getMovies()), 0)


    def testRental(self):
        self.ctrl.addClient("name")
        self.ctrl.addMovie('t', 'd', 'g')
        self.ctrl.addRental(1, 1, datetime.datetime.now())
        self.assertEqual(self.ctrl.getRentalByMovieId(1).getClientId(), 1)
        self.assertEqual(len(self.ctrl.getRentedMovies()), 1)

        self.ctrl.undo()
        self.assertEqual(len(self.ctrl.getRentedMovies()), 0)

        self.ctrl.redo()
        self.assertEqual(len(self.ctrl.getRentedMovies()), 1)

        self.assertEqual(self.ctrl.getRentalByMovieId(1).getReturnedDate(), -1)
        self.ctrl.returnMovie(1, datetime.datetime.now())
        self.assertNotEqual(self.ctrl.getRentalByMovieId(1).getReturnedDate(), -1)

        self.ctrl.undo()
        self.assertEqual(self.ctrl.getRentalByMovieId(1).getReturnedDate(), -1)
        self.ctrl.redo()
        self.assertNotEqual(self.ctrl.getRentalByMovieId(1).getReturnedDate(), -1)


    def runTests(self):
        # create a new controller for testing purposes
        self.ctrl = Controller()

        self.testClientFunctions()
        self.testMovieFunctions()
        self.testRental()