'''
This module contains functions that help the main program, but are not part of what we need to output
'''

commandList = []

errorCodesVars = [
    INVALID_NUM_OF_ARGS,
    INVALID_ARGS,
    INVALID_ARGS_OR_NUM_OF_ARGS,
    INVALID_SIGN,
    SCORE_NOT_WITHIN_BOUNDS,
    INVALID_NEW_SCORE,
    INVALID_INDEX,
    SCORES_NOT_WITHIN_RANGE,
    INVALID_PROBLEM_NO,
    NO_COMMANDS_GIVEN_YET
] = range(2, 12)

errorCodes = {
    None                         : "CHANGE ME - LAST FUNCTION RETURNED NONE",
    INVALID_NUM_OF_ARGS          : "Invalid number of arguments given!",
    INVALID_ARGS                 : "Invalid arguments given!",
    INVALID_ARGS_OR_NUM_OF_ARGS  : "Invalid arguments or number of arguments given!",
    INVALID_SIGN                 : "Invalid sign given!",
    SCORE_NOT_WITHIN_BOUNDS      : "Score must be between 0 and 10!",
    INVALID_NEW_SCORE            : "The new score is invalid!",
    INVALID_INDEX                : "The given index/indices is/are out of range!",
    SCORES_NOT_WITHIN_RANGE      : "Scores are not within range!",
    INVALID_PROBLEM_NO           : "Problem number must be between 1 and 3!",
    NO_COMMANDS_GIVEN_YET        : "There are no commands that can be undone!"
}

def checkProblemNoIsWithinBounds(problemNo):
    return problemNo >= 1 and problemNo <= 3


def checkArgIsInt(arg):
    '''
    :param arg: string
    :return: True if the string only contains digits
             False otherwise
    '''
    return arg.isdigit()


def checkArgsLength(args, length):
    '''
    :param args: list of strings
    :param length: integer
    :return: True if the number of arguments is equal to the given length
             False otherwise
    '''

    try:
        assert(len(args) == length)
    except AssertionError:
        return False

    return True


def checkScores(score1, score2, score3):
    '''
    Check if scores are within range (>= 0 and <= 10)
    '''

    try:
        assert (score1 >= 0 and score1 <= 10 and
                score2 >= 0 and score2 <= 10 and
                score3 >= 0 and score3 <= 10)
    except AssertionError:
        return False

    return True


def checkScore(score):
    '''
    :param score: integer
    :return: True if score >= 0 and score <= 10
             False otherwise
    '''
    #if score < 0 or score > 10:
    #    print("Score must be between 0 and 10!")
    #    return False

    #return True

    try:
        assert(score >= 0 and score <= 10)
    except AssertionError:
        return False

    return True


def readInteger(text):
    while True:
        try:
           option = input(text)

           assert checkArgIsInt(option) == True

           return int(option)
        except AssertionError:
            continue


def readCommand(text):
    cmd = input(text)

    # fix "     list" which would return unknown command otherwise
    cmd = cmd.lstrip(' ')

    if cmd.find(' ') == -1:
        # cmd is command name and there are no arguments
        return cmd, ""

    commandName = cmd[0:cmd.find(' ')]
    args = cmd[cmd.find(' '):]

    # first case example: "remove 1 to 3"
    if cmd.find(',') == -1:
        args = args.split(' ')
    # second case example: "add score1, score2, score3"
    else:
        args = args.split(',')


    for i in range(len(args)):
        args[i] = args[i].strip(' ')

    # remove spaces (ex: "list      sorted")
    args = [arg for arg in args if len(arg) > 0]

    return commandName, args