from utilities import readCommand
from testingUtils import testInsertValues
from commands import *


def main():
    # this will be a list of lists
    scoreList = []

    # for testing purposes
    testInsertValues(scoreList)

    commands = {
        "add" : addScore,
        "insert" : insertAtPosition,
        "remove" : removeCommand,
        "replace" : replaceScore,
        "list" : listCommand,
        "avg" : avgScores,
        "min" : minScores,
    }

    while True:
        command = readCommand()
        #print(str(command[0]) + " -- " + str(command[1]))

        if command[0] in commands.keys():
            commands[command[0]](scoreList, command[1])
        else:
            print("Unknown command!")


main()