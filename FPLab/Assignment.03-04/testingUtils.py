'''
This module contains the functions used for testing the main program
'''

from commands import *


def testInsertValuesInc(scoreList):
    '''
    Insert random values (increasing values), used for testing the program's features
    '''
    scoreList.append([0, 1, 2])
    scoreList.append([1, 2, 3])
    scoreList.append([2, 3, 4])
    scoreList.append([3, 4, 5])
    scoreList.append([4, 5, 6])
    scoreList.append([5, 6, 7])
    scoreList.append([6, 7, 8])
    scoreList.append([7, 8, 9])
    scoreList.append([8, 9, 10])


def testInsertValuesDec(scoreList):
    '''
    Insert random values (decreasing values), used for testing the program's features
    '''
    scoreList.append([8, 9, 10])
    scoreList.append([7, 8, 9])
    scoreList.append([6, 7, 8])
    scoreList.append([5, 6, 7])
    scoreList.append([4, 5, 6])
    scoreList.append([3, 4, 5])
    scoreList.append([2, 3, 4])
    scoreList.append([1, 2, 3])
    scoreList.append([0, 1, 2])


def testInsertValuesNoOrder(scoreList):
    '''
    Insert random values (in no particular order), used for testing the program's features
    '''
    scoreList.append([5, 3, 7])
    scoreList.append([3, 1, 2])
    scoreList.append([8, 1, 1])
    scoreList.append([0, 5, 4])
    scoreList.append([7, 1, 9])
    scoreList.append([10, 1, 4])
    scoreList.append([6, 6, 2])
    scoreList.append([9, 10, 10])
    scoreList.append([3, 7, 8])


def testAddScore(scoreList):
    scoreList = []
    addScore(scoreList, ['3', '4', '5'])
    assert scoreList == [[3, 4, 5]]

    scoreList = []
    addScore(scoreList, ['1', '1', '7'])
    assert scoreList == [[1, 1, 7]]


def testSumOfScores():
    assert sumOfScores([0, 0, 0]) == 0
    assert sumOfScores([0, 1, 2]) == 3
    assert sumOfScores([10, 10, 10]) == 30


def testAverageScore():
    assert averageScore([0, 0, 0]) == 0
    assert averageScore([1, 2, 3]) == 2
    assert averageScore([9, 9, 3]) == 7


def testLowestAverage():
    scoreList = [[5, 3, 7]]
    assert determineLowestAverage(scoreList, 0, 0) == 5

    scoreList = [[1, 1, 1]]
    assert determineLowestAverage(scoreList, 0, 0) == 1


def testReplaceScore():
    scoreList = [[1, 2, 3]]
    replaceScore(scoreList, ['0', 'P1', 'with', '5'])
    assert scoreList == [[5, 2, 3]]

    scoreList = [[0, 0, 0], [5, 6, 7]]
    replaceScore(scoreList, ['1', 'P3', 'with', '1'])
    assert scoreList == [[0, 0, 0], [5, 6, 1]]


def testRemoveParticipant():
    scoreList = [[1, 2, 3]]
    removeFromPosition(scoreList, 0)
    assert scoreList == []

    scoreList = [[0, 0, 0], [5, 6, 7]]
    removeFromPosition(scoreList, 1)
    assert scoreList == [[0, 0, 0]]


def testRemoveLessEquGreaterThan():
    scoreList = [ [0, 0, 0], [1, 2, 3], [3, 4, 5], [4, 4, 4] ]
    removeLessEquGreaterThan(scoreList, '<', 100)
    assert scoreList == []


def testRemoveFromIToJ():
    scoreList = [ [1, 2, 3], [3, 4, 5], [4, 5, 6], [0, 1, 1] ]
    removeFromIToJ(scoreList, 1, 2)
    assert scoreList == [ [1, 2, 3], [0, 1, 1] ]

    scoreList = [[0, 0, 0]]
    removeFromIToJ(scoreList, 0, 0)
    assert scoreList == []
