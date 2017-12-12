from controller import *

class RunTester:
    def __init__(self, ctrl):
        self.ctrl = ctrl

    def testAddClients(self):
        self.ctrl.addClient("Aa")
        self.ctrl.addClient("Bb")
        self.ctrl.addClient("Xx")
        self.ctrl.addClient("Hh")
        self.ctrl.addClient("Qz")
        self.ctrl.addClient("Kl")


    def testAddMovies(self):
        self.ctrl.addMovie("t1", "d1", "g1")
        self.ctrl.addMovie("t2", "d2", "g2")
        self.ctrl.addMovie("t3", "d3", "g3")
        self.ctrl.addMovie("t4", "d4", "g4")
        self.ctrl.addMovie("t5", "d5", "g5")
        self.ctrl.addMovie("t6", "d6", "g6")

    def run(self):
        self.testAddClients()
        self.testAddMovies()