'''
This file contains all the commands of the program

commands:
[DONE] add <p1 score> <p2 score> <p3 score>
[DONE] insert <p1 score> <p2 score> <p3 score> at <position>

[DONE] remove <position>
[DONE] remove <start position> to <end position>
[DONE] replace <old score> <P1 | P2 | P3> with <new score>

[DONE] list
[DONE] list sorted
[DONE] list [ < | = | > ] <score>

[DONE] avg <start position> to <end position>
[DONE] min <start position> to <end position>

top <number>
top <number> <P1 | P2 | P3>
remove [ < | = | > ] <score>

undo
'''

#from utilities import checkArgsLength, checkScore, checkScores, checkArgIsInt, errorCodesVars, errorCodes
# We need to import everything from utilities, otherwise we can't print error codes
from utilities import *

def addScore(scoreList, args):
    '''
    Append (at the end of scoreList) new scores for problems P1, P2 and P3
    '''
    # check if we're within bounds
    if not checkArgsLength(args, 3):
        return INVALID_NUM_OF_ARGS

    if not checkScores(int(args[0]), int(args[1]), int(args[2])):
        return SCORES_NOT_WITHIN_RANGE

    scoreList.append([int(args[0]), int(args[1]), int(args[2])])

    return True


def insertAtPosition(scoreList, args):
    '''
    Insert new scores at a given position within scoreList
    Syntax: insert <p1 score> <p2 score> <p3 score> at <position>
    '''

    if not checkArgsLength(args, 5):
        return INVALID_NUM_OF_ARGS

    if not checkArgIsInt(args[0]) or not checkArgIsInt(args[1]) or not checkArgIsInt(args[2]) or not checkArgIsInt(args[4]):
        return INVALID_ARGS

    checkScores(int(args[0]), int(args[1]), int(args[2]))

    scoreList.insert(int(args[4]), [ int(args[0]), int(args[1]), int(args[2]) ])

    return True


def removeFromPosition(scoreList, position):
    '''
    Remove element situated on index 'position' from scoreList
    '''

    if position >= 0 and position < len(scoreList):
        # the next 2 lines do the same thing
        #del(scoreList[position])
        scoreList.pop(position)
    else:
        return INVALID_INDEX

    return True


def removeFromIToJ(scoreList, startIndex, endIndex):
    '''
    Remove elements situated between indexes startIndex and endIndex from scoreList
    '''

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
    for i in range(0, endIndex - startIndex + 1):
        scoreList.pop(startIndex)

    return True


def removeCommand(scoreList, args):
    '''
    Determine what the user meant
    remove <position>
    remove <start position> to <end position>
    '''

    # remove <position>
    if len(args) == 1:
        if not checkArgIsInt(args[0]):
            return INVALID_ARGS

        removeFromPosition(scoreList, int(args[0]))
    # remove <start position> to <end position>
    elif len(args) == 3:
        if not checkArgIsInt(args[0]) or not checkArgIsInt(args[2]):
            return INVALID_ARGS

        removeFromIToJ(scoreList, int(args[0]), int(args[2]))
    else:
        return INVALID_NUM_OF_ARGS

    return True


def replaceScore(scoreList, args):
    #print(args)

    # index in scoreList
    idToReplace = int(args[0])

    # problem number is the second character of the second argument
    # example: P1 => 1 is the problem id
    # but we have the problems numbered from 0 in scoreList
    problemNo = int(args[1][1]) - 1

    newScore = int(args[3])

    if newScore < 0 or newScore > 10:
        return INVALID_NEW_SCORE

    #print(str(idToReplace) + " " + str(problemNo) + " " + str(newScore))

    scoreList[idToReplace][problemNo] = newScore

    return True


def listScores(scoreList):
    print(scoreList)


def sortScores(scoreList):
    '''
    :param scoreList: unsorted score list
    :return: score list in decreasing order, based on their score
    '''

    sortedScores = scoreList[:]
    sortedScores.sort(key = sum, reverse = True)

    return sortedScores


def listSortedScores(scoreList):
    '''
    Print participants sorted in decreasing order of their average score
    '''

    listScores(sortScores(scoreList))


def listScoresLessEquBiggerThan(scoreList, args):
    sign = args[0]
    givenScore = int(args[1])

    if not checkScore(givenScore):
        return SCORE_NOT_WITHIN_BOUNDS

    if sign == '<':
        for lst in scoreList:
            if sum(lst) < givenScore:
                print(lst, end = ' ')
        print()
    elif sign == '=':
        for lst in scoreList:
            if sum(lst) == givenScore:
                print(lst, end  = ' ')
        print()
    elif sign == '>':
        for lst in scoreList:
            if sum(lst) > givenScore:
                print(lst, end = ' ')
        print()
    else:
        return INVALID_SIGN

    return True


def listCommand(scoreList, args):
    '''
    Determine what the user meant
    list
    list sorted
    list [ < | = | > ] <score>
    '''

    if len(args) == 0:
        listScores(scoreList)
    elif len(args) == 1 and args[0] == "sorted":
        listSortedScores(scoreList)
    elif len(args) == 2 and args[0] in "<=>" and checkArgIsInt(args[1]):
        listScoresLessEquBiggerThan(scoreList, args)
    else:
        return INVALID_ARGS_OR_NUM_OF_ARGS

    return True


def sumOfScores(scores):
    '''
    Returns the sum of a participant's scores
    Params: scores - list
    '''

    return sum(scores)


def averageScore(scores):
    '''
    Return the average score of a participant
    The returned value is an integer
    '''

    return int(sumOfScores(scores) / len(scores))


def avgScores(scoreList, args):
    '''
    Print the average of the average scores for participants between two given positions

    Syntax: avg <start position> to <end position>
    '''

    sumOfTheAverages = 0
    for i in range(int(args[0]), int(args[2]) + 1):
        sumOfTheAverages += averageScore(scoreList[i])

    print("The sum of the average scores for participants " + args[0] + " to " + args[2] + " is " + str(int(sumOfTheAverages / (int(args[2]) - int(args[0]) + 1))))


def determineLowestAverage(scoreList, startIndex, endIndex):
    '''
    :param scoreList: list
    :param startIndex: starting index for determining the lowest average
    :param endIndex: ending index for determining the lowest average
    :return: the lowest average of the scores for the participants found in scoreList between indices startIndex and endIndex
    '''
    lowestAvg = averageScore(scoreList[startIndex])

    # we increment startIndex because we have already calculated
    # the average score for the participant found on the intial starting index
    startIndex += 1

    while (startIndex <= endIndex):
        currentAvg = averageScore(scoreList[startIndex])
        if currentAvg < lowestAvg:
            lowestAvg = currentAvg

        startIndex += 1

    return lowestAvg


def minScores(scoreList, args):
    '''
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

    for i in range(int(args[0])):
        outputString += str(i + 1) + ": " + str(sortedScores[i]) + '\n'

    return outputString


def sortScoreListByProblem(scoreList, problemNo):
    '''
    :param scoreList: unordered list
    :param problemNo: the problem number that we sort the score list by
    :return: ordered score list in descending order, the key being the given problem number
    '''
    sortedScores = sortScores(scoreList)
    # sort the score list by the problem number in reverse
    sortedScores.sort(key = lambda lst: lst[problemNo], reverse = True)

    return sortedScores


def topParticipantsForProblem(scoreList, args):
    '''
    :param scoreList: unordered list
    :param args: string - contains the number of participants to print and the problem numer
    :return: top n participants for given problem

    Syntax: top <number> <P1 | P2 | P3>
    '''
    # stupid case, if we write "1" instead of "P1", for example
    if not checkArgsLength(args[1], 2):
        return INVALID_ARGS

    if not checkArgIsInt(args[0]) or not checkArgIsInt(args[1][1]):
        return INVALID_ARGS

    if not checkProblemNoIsWithinBounds(int(args[1][1])):
        return INVALID_PROBLEM_NO

    sortedScores = sortScoreListByProblem(scoreList, int(args[1][1]) - 1)

    outputString = ""
    for i in range(int(args[0])):
        outputString += str(i + 1) + ": " + str(sortedScores[i]) + '\n'

    return outputString


def topCommand(scoreList, args):
    '''
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