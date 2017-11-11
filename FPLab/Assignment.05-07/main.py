#import userinterface as ui
from userinterface import UserInterface
from runtests import *
from utilities import Utilities
from controller import Controller

'''
class main:
    def __init__(self):
        pass

    def start(self):
        ui.run()
'''

def start():
    utils = Utilities()
    ctrl = Controller()
    rt = RunTester(ctrl)
    rt.run()

    ui = UserInterface(utils, ctrl)
    ui.run()

start()