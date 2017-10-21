'''
This file contains all the commands of the program

commands:
[DONE] add <p1 score> <p2 score> <p3 score>
[DONE] insert <p1 score> <p2 score> <p3 score> at <position>

[DONE] remove <position>
[DONE] remove <start position> to <end position>
[DONE] replace <old score> <P1 | P2 | P3> with <new score>

[DONE] list
list sorted
list [ < | = | > ] <score>

[DONE] avg <start position> to <end position>
min <start position> to <end position>

top <number>
top <number> <P1 | P2 | P3>
remove [ < | = | > ] <score>

undo
'''

from utilities import checkScores

def addScore(scoreList, args):
    '''
    Append (at the end of scoreList) new scores for problems P1, P2 and P3
    '''
    # check if we're within bounds
    assert(len(args) == 3)
    checkScores(int(args[0]), int(args[1]), int(args[2]))

    scoreList.append([int(args[0]), int(args[1]), int(args[2])])
    #print(scoreList)
    #print(args)


def insertAtPosition(scoreList, args):
    '''
    Insert new scores at a given position within scoreList
    Syntax: insert <p1 score> <p2 score> <p3 score> at <position>
    '''

    assert(len(args) == 5)
    checkScores(int(args[0]), int(args[1]), int(args[2]))

    scoreList.insert(int(args[4]), [ int(args[0]), int(args[1]), int(args[2]) ])


def removeFromPosition(scoreList, position):
    '''
    Remove element situated on index 'position' from scoreList
    '''

    if position >= 0 and position < len(scoreList):
        # the next 2 lines do the same thing
        #del(scoreList[position])
        scoreList.pop(position)
    else:
        print("Entered index is not valid!")


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


def removeCommand(scoreList, args):
    '''
    Determine what the user meant
    remove <position>
    remove <start position> to <end position>
    '''
    #print("args are " + str(args))
    #print("LEN ARGS " + str(len(args)))

    # remove <position>
    if len(args) == 1:
        removeFromPosition(scoreList, int(args[0]))
    # remove <start position> to <end position>
    elif len(args) == 3:
        removeFromIToJ(scoreList, int(args[0]), int(args[2]))


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
        print("The new score is invalid!")
        return

    #print(str(idToReplace) + " " + str(problemNo) + " " + str(newScore))

    scoreList[idToReplace][problemNo] = newScore


def listScores(scoreList):
    print(scoreList)


def listSortedScores(scoreList):
    '''
    Print participants sorted in decreasing order of their average score
    '''
    sortedScores = scoreList[:]


def listScoresLessEquBiggerThan(scoreList, sign):
    pass


def listCommand(scoreList, args):
    '''
    Determine what the user meant
    list
    list sorted
    list [ < | = | > ] <score>
    '''

    if len(args) == 0:
        listScores(scoreList)
    elif len(args) == 1:
        listSortedScores(scoreList)
    else: # == 3
        listScoresLessEquBiggerThan(scoreList, args[0])


def sumOfScores(scores):
    '''
    Returns the sum of a participant's scores
    Params: scores - list
    '''

    return sum(scores)


def averageScores(scores):
    '''
    Return the average score of a participant
    The returned value is an integer
    '''

    #print("sum: " + str(sumOfScores(scores)))
    return int(sumOfScores(scores) / len(scores))


def avgScores(scoreList, args):
    '''
    Print the average of the average scores for participants between two given positions

    Syntax: avg <start position> to <end position>
    '''

    #print("ARGS ARE " + str(args))

    sumOfTheAverages = 0
    for i in range(int(args[0]), int(args[2]) + 1):
        sumOfTheAverages += averageScores(scoreList[i])

    #print(sumOfTheAverages)

    print("The sum of the average scores for participants " + args[0] + " to " + args[2] + " is " + str(int(sumOfTheAverages / (int(args[2]) - int(args[0]) + 1))))


def minScores(scoreList, args):
    '''
    Print the lowest average score of the participants between two given positions
    '''

    pass


def topCommand():
    '''
    ciu ciu
    '''
    pass