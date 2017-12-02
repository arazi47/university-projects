from controller import Controller
from tests.TestController import TestController
from userinterface import UserInterface
from utilities import Utilities


def start():
    utils = Utilities()
    ctrl = Controller()

    testctrl = TestController()
    testctrl.runTests()

    ui = UserInterface(utils, ctrl)
    ui.run()

start()
