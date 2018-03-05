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

def runTests():
    scoreList = []
    testAddScore(scoreList)
    testSumOfScores()
    testAverageScore()
    testLowestAverage()
    testReplaceScore()
    testRemoveParticipant()
    testRemoveLessEquGreaterThan()
    testRemoveFromIToJ()

    commands.commandList = []

def printMenu():
    print("1. Add participant to list")
    print("2. Insert participant at position")
    print("3. Remove participant at position")
    print("4. Remove participants between two given positions")
    print("5. Replace the score of a problem for a participant")
    print("6. List participants")
    print("7. List participants sorted in decreasing order by their score")
    print("8. List participants with score less/equal/greater than a given score")
    print("9. Average score between 2 given positions")
    print("10. Lowest average score between 2 given positions")
    print("11. Top n participants")
    print("12. Top n participants for a given problem")
    print("13. Remove participants with a score less/equal/greater than a given score")
    print("14. Undo")
    print("15. Exit")


def menuAddParticipantToList(scoreList):
    s1 = utilities.readInteger("Score 1: ")
    s2 = utilities.readInteger("Score 2: ")
    s3 = utilities.readInteger("Score 3: ")

    printCommandResult(commands.addScore(scoreList, [str(s1), str(s2), str(s3)]))


def menuInsertParticipantAtPosition(scoreList):
    s1 = utilities.readInteger("Score 1: ")
    s2 = utilities.readInteger("Score 2: ")
    s3 = utilities.readInteger("Score 3: ")
    pos = utilities.readInteger("Position: ")

    printCommandResult(commands.insertAtPosition(scoreList, [str(s1), str(s2), str(s3), 'at', str(pos)]))


def menuRemoveParticipantAtPosition(scoreList):
    pos = utilities.readInteger("Position: ")

    printCommandResult(commands.removeFromPosition(scoreList, pos))


def menuRemoveFromIToJ(scoreList):
    pos1 = utilities.readInteger("Position 1: ")
    pos2 = utilities.readInteger("Position 2: ")

    printCommandResult(commands.removeFromIToJ(scoreList, pos1, pos2))


def menuRemoveLessEquGreaterThan(scoreList):
    sign = readCommand("Sign (<, =, >): ")
    score = utilities.readInteger("Score: ")

    printCommandResult(commands.removeLessEquGreaterThan(scoreList, sign[0], score))


def menuTopNCommandByProblemId(scoreList):
    participantsLimit = utilities.readInteger("How many participants do you want to see? ")
    problemNo = utilities.readInteger("Problem number (1, 2, 3): ")

    printCommandResult(commands.topCommand(scoreList, [str(participantsLimit), 'P' + str(problemNo)]))


def menuTopNCommand(scoreList):
    participantsLimit = utilities.readInteger("How many participants do you want to see? ")

    printCommandResult(commands.topCommand(scoreList, [str(participantsLimit)]))


def menuMinScores(scoreList):
    pos1 = utilities.readInteger("Position 1: ")
    pos2 = utilities.readInteger("Position 2: ")

    printCommandResult(commands.minScores(scoreList, [str(pos1), 'to', str(pos2)]))


def menuAvgScores(scoreList):
    pos1 = utilities.readInteger("Position 1: ")
    pos2 = utilities.readInteger("Position 2: ")

    printCommandResult(commands.avgScores(scoreList, [str(pos1), 'to', str(pos2)]))


def menuListCommand(scoreList):
    sign = readCommand("Sign (<, =, >): ")
    score = utilities.readInteger("Score: ")

    # sign[0], because readCommand returns a command name and the arguments
    # hacks everywhere
    printCommandResult(commands.listCommand(scoreList, [sign[0], str(score)]))


def menuReplaceScore(scoreList):
    pos = utilities.readInteger("Position: ")
    problemNo = utilities.readInteger("Problem number (1, 2, 3): ")
    score = utilities.readInteger("Score: ")

    printCommandResult(commands.replaceScore(scoreList, [str(pos), 'P' + str(problemNo), 'with', str(score)]))


def runMenu():
    scoreList = []

    # used for testing
    testInsertValuesNoOrder(scoreList)

    while True:
        printMenu()

        option = utilities.readInteger(">> ")
        if option == 1:
            menuAddParticipantToList(scoreList)
        elif option == 2:
            menuInsertParticipantAtPosition(scoreList)
        elif option == 3:
            menuRemoveParticipantAtPosition(scoreList)
        elif option == 4:
            menuRemoveFromIToJ(scoreList)
        elif option == 5:
            menuReplaceScore(scoreList)
        elif option == 6:
            printCommandResult(commands.listCommand(scoreList, ""))
        elif option == 7:
            printCommandResult(commands.listCommand(scoreList, ["sorted"]))
        elif option == 8:
            menuListCommand(scoreList)
        elif option == 9:
            menuAvgScores(scoreList)
        elif option == 10:
            menuMinScores(scoreList)
        elif option == 11:
            menuTopNCommand(scoreList)
        elif option == 12:
            menuTopNCommandByProblemId(scoreList)
        elif option == 13:
            menuRemoveLessEquGreaterThan(scoreList)
        elif option == 14:
            printCommandResult(commands.undo(scoreList, ""))
        elif option == 15:
            exit()
        else:
            print("Unknown option!")


def run():
    # this will be a list of lists of 3 integers each
    scoreList = []

    # for testing purposes
    #testInsertValuesNoOrder(scoreList)

    commandsDict = {
        "add" : commands.addScore,
        "insert" : commands.insertAtPosition,
        "remove" : commands.removeCommand,
        "replace" : commands.replaceScore,
        "list" : commands.listCommand,
        "avg" : commands.avgScores,
        "min" : commands.minScores,
        "top" : commands.topCommand,
        "undo" : commands.undo
    }

    while True:
        command = utilities.readCommand(">> ")

        if command[0] in ["exit", "quit"]:
            exit()
        elif command[0] in commandsDict.keys():
            printCommandResult(commandsDict[command[0]](scoreList, command[1]))
        else:
            print("Unknown command!")