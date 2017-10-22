'''
This module contains the functions used for testing the main program
'''

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
