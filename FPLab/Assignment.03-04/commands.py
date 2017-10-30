'''
This file contains all the commands of the program

commands:
[DONE] add <p1 score> <p2 score> <p3 score>
[DONE] insert <p1 score> <p2 score> <p3 score> at <position>

[DONE] remove <position>
[DONE] remove <start position> to <end position>
[DONE] replace <position> <P1 | P2 | P3> with <new score>

[DONE] list
[DONE] list sorted
[DONE] list [ < | = | > ] <score>

[DONE] avg <start position> to <end position>
[DONE] min <start position> to <end position>

[DONE] top <number>
[DONE] top <number> <P1 | P2 | P3>
[DONE] remove [ < | = | > ] <score>

[DONE] undo

counter functions:
[DONE] counterAdd
[DONE] counterInsertAtPosition
[DONE] counterRemovePos
[DONE] counterRemoveIToJ
[DONE] counterReplace
[DONE] counterRemoveLessEquGreaterThan
'''

#from utilities import checkArgsLength, checkScore, checkScores, checkArgIsInt, errorCodesVars, errorCodes
# We need to import everything from utilities, otherwise we can't print error codes
from utilities import *

#**********************************************************************************************#
'''
Counterfunctions begin here
'''

def counterAdd(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: empty list
    :return: None

    Removes the participant found at the end of the score list
    '''

    scoreList.pop(len(scoreList) - 1)


def counterInsertAtPosition(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: ['insertAtPos', indexToBeRemoved]
    :return: None

    Removes the participant found at index indexToBeRemoved
    We can use one of the functions we have defined before
    '''

    removeFromPosition(scoreList, int(args[1]))


def counterRemovePos(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: ['removePos', ['<p1 score>', '<p2 score'>, '<p3 score>', 'at', indexToAdd]]
    :return: None

    Add participant with scores [<p1 score>, <p2 score>, <p3 score>] at position indexToAdd
    '''

    insertAtPosition(scoreList, args[1])


def counterRemoveIToJ(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: ['removeIToJ', startIndex, [...]]
    :return: None

    Insert the list of integers found at args[2] starting from startIndex
    '''

    startIndex = int(args[1])
    scoreList[startIndex:startIndex] = list(args[2])


def counterReplace(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list: ['replace', indexToReplace, problemNo, oldScore]
    :return: None

    Replaces the score of problemNo of the participant found at indexToReplace with oldScore
    '''

    indexToReplace = int(args[1])
    problemNo = int(args[2])
    oldScore = int(args[3])

    scoreList[indexToReplace][problemNo] = oldScore

def counterRemoveLessEquGreaterThan(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: ['removeLessEquGreaterThan', oldScoreList]
    :return: None

    Replace the current scoreList with the one before the remove <=> function
    '''

    scoreList[:] = args[1]

'''
Counterfunctions end here
'''
#**********************************************************************************************#

def generateListOfScores(score1, score2, score3):
    return [score1, score2, score3]

def addScore(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: True if all the checks pass

    Append (at the end of scoreList) a new participant
    Syntax: add <score1>, <score2>, <score3>
    '''

    # check if we're within bounds
    if not checkArgsLength(args, 3) or not checkArgIsInt(args[0]) or not checkArgIsInt(args[1]) or not checkArgIsInt(args[2]):
        return INVALID_ARGS_OR_NUM_OF_ARGS

    if not checkScores(int(args[0]), int(args[1]), int(args[2])):
        return SCORES_NOT_WITHIN_RANGE

    scores = generateListOfScores(int(args[0]), int(args[1]), int(args[2]))
    scoreList.append(scores)

    commandList.append(["add"])

    return True


def insertAtPosition(scoreList, args):
    '''
    :param scoreList: list
    :param args: list of strings
    :return: True if all checks pass

    Insert new scores at a given position within scoreList
    Syntax: insert <p1 score> <p2 score> <p3 score> at <position>
    '''

    if not checkArgsLength(args, 5):
        return INVALID_NUM_OF_ARGS

    if not checkArgIsInt(args[0]) or not checkArgIsInt(args[1]) or not checkArgIsInt(args[2]) or not checkArgIsInt(args[4]):
        return INVALID_ARGS

    if not checkScores(int(args[0]), int(args[1]), int(args[2])):
        return INVALID_ARGS

    position = int(args[4])
    if position >= 0 and position < len(scoreList):
        scoreList.insert(int(args[4]), [ int(args[0]), int(args[1]), int(args[2]) ])
    else:
        return INVALID_INDEX

    commandList.append(["insertAtPos", int(args[4])])

    return True


def removeFromPosition(scoreList, position):
    '''
    :param scoreList: list
    :param position: integer
    :return: True if all checks pass

    Remove element situated on index 'position' from scoreList
    Syntax: remove <position>
    '''

    if not checkArgIsInt(str(position)):
        return INVALID_ARGS

    if position >= 0 and position < len(scoreList):
        commandList.append(["removePos", [ str(scoreList[position][0]), str(scoreList[position][1]), str(scoreList[position][2]), "at", str(position)] ])

        # the next 2 lines do the same thing
        # del(scoreList[position])
        scoreList.pop(position)
    else:
        return INVALID_INDEX

    return True


def removeFromIToJ(scoreList, startIndex, endIndex):
    '''
    :param scoreList: list of lists of integers
    :param startIndex: integer
    :param endIndex: integer
    :return: True

    Remove elements from scoreList situated between indices startIndex and endIndex
    '''

    # so we don't crash at startIndex = -1, for example
    if not checkArgIsInt(str(startIndex)) or not checkArgIsInt(str(endIndex)):
        return INVALID_INDEX

    if startIndex < 0 or startIndex >= len(scoreList):
        return INVALID_INDEX

    if not endIndex < 0 and endIndex >= len(scoreList):
        return INVALID_INDEX

    # why would anyone do this, tho?
    if startIndex > endIndex:
        startIndex, endIndex = endIndex, startIndex

    # This does not work!
    #while startIndex <= endIndex:
    #    scoreList.pop(startIndex)
    #   startIndex += 1

    # For example we have startIndex = 1, endIndex = 3
    # First we pop startIndex, to remove the first element
    # Then the next element we need to remove falls on startIndex
    # So all we have to do is delete the starting index
    # endIndex - startIndex + 1 times
    # For startIndex = 1, endIndex = 3, we need to delete indices 1, 2 and 3
    # So 3 - 1 + 1

    removedScores = []
    for i in range(0, endIndex - startIndex + 1):
        removedScores.append(scoreList[startIndex])
        scoreList.pop(startIndex)

    commandList.append(["removeIToJ", startIndex, removedScores])

    return True


def removeLessEquGreaterThan(scoreList, sign, givenScore):
    '''
    :param scoreList: list of lists of integers
    :param sign: character string (can be: <, =, >)
    :param givenScore: integer
    :return: True
    '''

    commandList.append(["removeLessEquGreaterThan", scoreList[:]])

    if sign == "<":
        # without "[:]", the list wouldn't change outside the function
        scoreList[:] = [lst for lst in scoreList if averageScore(lst) > givenScore]
    elif sign == "=":
        scoreList[:] = [lst for lst in scoreList if averageScore(lst) == givenScore]
    else: # sign == ">":
        scoreList[:] = [lst for lst in scoreList if averageScore(lst) < givenScore]

    return True


def removeCommand(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: the specific function, an error code, or True if neither

    This function determines what command did the user mean

    Syntax:
    remove <position>
    remove [ < | = | > ] <score>
    remove <start position> to <end position>
    '''

    # remove <position>
    if len(args) == 1:
        if not checkArgIsInt(args[0]):
            return INVALID_ARGS

        removeFromPosition(scoreList, int(args[0]))
    # remove [ < | = | > ] <score>
    elif len(args) == 2:
        if not args[0] in "<=>" or not checkArgIsInt(args[1]):
            return INVALID_ARGS

        return removeLessEquGreaterThan(scoreList, args[0], int(args[1]))

    # remove <start position> to <end position>
    elif len(args) == 3:
        if not checkArgIsInt(args[0]) or not checkArgIsInt(args[2]):
            return INVALID_ARGS

        return removeFromIToJ(scoreList, int(args[0]), int(args[2]))
    else:
        return INVALID_NUM_OF_ARGS

    return True


def replaceScore(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: True if all checks pass

    Syntax: replace <position> <P1 | P2 | P3> with <new score>
    '''

    if not checkArgsLength(args, 4) or not checkArgIsInt(args[0]) or not checkArgIsInt(args[1][1]) or not checkArgIsInt(args[3]):
        return INVALID_ARGS_OR_NUM_OF_ARGS

    # index in scoreList
    idToReplace = int(args[0])

    # problem number is the second character of the second argument
    # example: P1 => 1 is the problem id
    # but we have the problems numbered from 0 in scoreList
    problemNo = int(args[1][1]) - 1
    if not checkProblemNoIsWithinBounds(problemNo + 1):
        return INVALID_PROBLEM_NO

    newScore = int(args[3])

    if not checkScore(newScore):
        return INVALID_NEW_SCORE

    commandList.append(["replace", idToReplace, problemNo, scoreList[idToReplace][problemNo]])

    scoreList[idToReplace][problemNo] = newScore

    return True


def listScores(scoreList):
    '''
    :param scoreList: list of lists of integers
    :return: scoreList
    '''

    return scoreList


def sortScores(scoreList):
    '''
    :param scoreList: unsorted list of lists of integers
    :return: sorted scoreList
    '''

    sortedScores = scoreList[:]
    sortedScores.sort(key = sum, reverse = True)

    return sortedScores


def listSortedScores(scoreList):
    '''
    :param scoreList: list of lists of integers
    :return: sorted scoreList

    Print participants sorted in decreasing order of their average score
    '''

    return sortScores(scoreList)


# @todo sum of the scores, or average?
def listScoresLessEquGreaterThan(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: string containing the scores that are less, equal or bigger than a given score

    Syntax: list [ < | = | > ] <score>
    '''

    if not checkArgsLength(args, 2):
        return INVALID_NUM_OF_ARGS

    sign = args[0]

    if not sign in "<=>" or not checkArgIsInt(args[1]):
        return INVALID_ARGS

    givenScore = int(args[1])

    if not checkScore(givenScore):
        return SCORE_NOT_WITHIN_BOUNDS

    outputString = ""
    if sign == '<':
        for lst in scoreList:
            if sum(lst) < givenScore:
                outputString += "[" + str(lst[0]) + ", " + str(lst[1]) + ", " + str(lst[2]) + "]\n"
    elif sign == '=':
        for lst in scoreList:
            if sum(lst) == givenScore:
                outputString += "[" + str(lst[0]) + ", " + str(lst[1]) + ", " + str(lst[2]) + "]\n"
    elif sign == '>':
        for lst in scoreList:
            if sum(lst) > givenScore:
                outputString += "[" + str(lst[0]) + ", " + str(lst[1]) + ", " + str(lst[2]) + "]\n"

    return outputString


def listCommand(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: sorted / unsorted score list, or an error


    Determine what the user meant
    list
    list sorted
    list [ < | = | > ] <score>
    '''

    # list
    if len(args) == 0:
        return listScores(scoreList)
    # list sorted
    elif len(args) == 1 and args[0] == "sorted":
        return listSortedScores(scoreList)
    # list [ < | = | > ] <score>
    elif len(args) == 2 and args[0] in "<=>" and checkArgIsInt(args[1]):
        return listScoresLessEquGreaterThan(scoreList, args)
    else:
        return INVALID_ARGS_OR_NUM_OF_ARGS


def sumOfScores(scores):
    '''
    :param scores: list of 3 integers
    :return: sum of scores
    '''

    return sum(scores)


def averageScore(scores):
    '''
    :param scores: list of 3 integers
    :return: the average score of a participant
    '''

    return int(sumOfScores(scores) / len(scores))


def avgScores(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: a string containing the average of the average scores or an error

    Print the average of the average scores for participants between two given positions

    Syntax: avg <start position> to <end position>
    '''

    if not checkArgsLength(args, 3) or not checkArgIsInt(args[0]) or not checkArgIsInt(args[2]):
        return INVALID_ARGS_OR_NUM_OF_ARGS

    sumOfTheAverages = 0
    for i in range(int(args[0]), int(args[2]) + 1):
        sumOfTheAverages += averageScore(scoreList[i])

    output = "The sum of the average scores for participants " + args[0] + " to " + args[2] + " is " + str(int(sumOfTheAverages / (int(args[2]) - int(args[0]) + 1)))

    return output


def determineLowestAverage(scoreList, startIndex, endIndex):
    '''
    :param scoreList: list of lists of integers
    :param startIndex: starting index for determining the lowest average
    :param endIndex: ending index for determining the lowest average
    :return: the lowest average of the scores for the participants found in scoreList between indices startIndex and endIndex
    '''
    lowestAvg = averageScore(scoreList[startIndex])

    # we increment startIndex because we have already calculated
    # the average score for the participant found on the initial starting index
    startIndex += 1

    while (startIndex <= endIndex):
        currentAvg = averageScore(scoreList[startIndex])
        if currentAvg < lowestAvg:
            lowestAvg = currentAvg

        startIndex += 1

    return lowestAvg


def minScores(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: a string containing the lowest average score or an error

    Print the lowest average score of the participants between two given positions

    Syntax: min <start position> to <end position>
    '''

    if not checkArgsLength(args, 3):
        return INVALID_NUM_OF_ARGS

    if not checkArgIsInt(args[0]) or not checkArgIsInt(args[2]):
        return INVALID_ARGS

    startIndex = int(args[0])
    endIndex = int(args[2])
    lowestAvg = determineLowestAverage(scoreList, startIndex, endIndex)

    output = "The lowest average score of the participants between the given positions is " + str(lowestAvg) + "."

    return output


def topParticipants(scoreList, args):
    '''
    :param scoreList: unordered list
    :param args: string -  contains the number of participants to print
    :return: top n participants

    Syntax: top <number>
    '''

    if not checkArgIsInt(args[0]):
        return INVALID_ARGS

    sortedScores = sortScores(scoreList)

    outputString = ""

    participantsLimit = int(args[0])
    if participantsLimit >= len(scoreList):
        return INVALID_INDEX

    for i in range(participantsLimit):
        outputString += str(i + 1) + ": " + str(sortedScores[i]) + '\n'

    return outputString


def sortScoreListByProblem(scoreList, problemNo):
    '''
    :param scoreList: unordered list of lists of integers
    :param problemNo: the problem number that we sort the score list by
    :return: ordered score list in descending order, the key being the given problem number
    '''

    sortedScores = sortScores(scoreList)
    # sort the score list by the problem number in reverse
    sortedScores.sort(key = lambda lst: lst[problemNo], reverse = True)

    return sortedScores


def topParticipantsForProblem(scoreList, args):
    '''
    :param scoreList: unordered list of lists of integers
    :param args: string - contains the number of participants to print and the problem number
    :return: top n participants for given problem or an error

    Syntax: top <number> <P1 | P2 | P3>
    '''

    # stupid case, if we write "1" instead of "P1", for example
    if not checkArgsLength(args[1], 2):
        return INVALID_ARGS

    if not checkArgIsInt(args[0]) or not checkArgIsInt(args[1][1]):
        return INVALID_ARGS

    if not checkProblemNoIsWithinBounds(int(args[1][1])):
        return INVALID_PROBLEM_NO

    if int(args[0]) >= len(scoreList):
        return INVALID_INDEX

    # - 1 because the problem indices start from 0 in our list
    problemNo = int(args[1][1]) - 1
    participantsLimit = int(args[0])

    sortedScores = sortScoreListByProblem(scoreList, problemNo)

    outputString = ""
    for i in range(participantsLimit):
        outputString += str(i + 1) + ": " + str(sortedScores[i]) + '\n'

    return outputString


def topCommand(scoreList, args):
    '''
    :param scoreList: list of lists of integers
    :param args: list of strings
    :return: top participants or an error, if all checks pass

    Determine what the user meant

    Syntax:
    top <number>
    top <number> <P1 | P2 | P3>
    '''

    if len(args) == 1:
        return topParticipants(scoreList, args)
    elif len(args) == 2:
        return topParticipantsForProblem(scoreList, args)
    else:
        return INVALID_NUM_OF_ARGS


def undo(scoreList, args):
    '''
    :param scoreList: list
    :param args: empty string
    :return: True

    counter functions:
    [DONE] counterAdd
    [DONE] counterInsertAtPosition
    [DONE] counterRemovePos
    [DONE]counterRemoveIToJ
    [DONE] counterReplace
    [DONE] counterRemoveLessEquGreaterThan
    '''

    if len(commandList) == 0:
        return NO_COMMANDS_GIVEN_YET

    lastCommand = commandList[len(commandList) - 1]

    if lastCommand[0] == "add":
        counterAdd(scoreList, lastCommand)
        commandList.pop(len(commandList) - 1)
    elif lastCommand[0] == "insertAtPos":
        counterInsertAtPosition(scoreList, lastCommand)
        commandList.pop(len(commandList) - 1)
    elif lastCommand[0] == "removePos":
        counterRemovePos(scoreList, lastCommand)
        commandList.pop(len(commandList) - 1)
    elif lastCommand[0] == "removeIToJ":
        counterRemoveIToJ(scoreList, lastCommand)
        commandList.pop(len(commandList) - 1)
    elif lastCommand[0] == "replace":
        counterReplace(scoreList, lastCommand)
        commandList.pop(len(commandList) - 1)
    elif lastCommand[0] == "removeLessEquGreaterThan":
        counterRemoveLessEquGreaterThan(scoreList, lastCommand)
        commandList.pop(len(commandList) - 1)
    else:
        return "Command not handled with name: " + lastCommand[0]

    return True