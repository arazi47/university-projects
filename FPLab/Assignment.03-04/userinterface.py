'''
This file handles all the input/output of the program
'''

import utilities
from testingUtils import *
#from commands import *
import commands

def printCommandResult(result):
    '''
    :param result: integer or string (depends on what a function returns)
    :return: None
    '''

    if result != True:
        # integer (error code)
        if utilities.checkArgIsInt(str(result)):
            print(utilities.errorCodes[result])
        else: # string (some output)
            print(result)

def run():
    # this will be a list of lists
    scoreList = []

    # for testing purposes
    testInsertValuesNoOrder(scoreList)

    commandsDict = {
        "add" : commands.addScore,
        "insert" : commands.insertAtPosition,
        "remove" : commands.removeCommand,
        "replace" : commands.replaceScore,
        "list" : commands.listCommand,
        "avg" : commands.avgScores,
        "min" : commands.minScores,
        "top" : commands.topCommand
    }

    while True:
        command = utilities.readCommand()

        if command[0] in ["exit", "quit"]:
            exit()
        elif command[0] in commandsDict.keys():
            printCommandResult(commandsDict[command[0]](scoreList, command[1]))
        else:
            print("Unknown command!")