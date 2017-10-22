'''
This module contains functions that help the main program, but are not part of what we need to output
'''

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


def readCommand():
    cmd = input(">> ")
    #commandName = cmd.split(' ')[0]
    #if firstWord in commands.keys():

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

    # for the first case "remove 1 to 3"
    # arguments would be ['', '1', 'to', '3']
    # we need to remove the ''
    #if cmd.find(',') == -1:
    #    args.pop(0)

    #for i in range(len(args)):
    #    if len(args[i]) == 0:
    #        args.pop(i)

    # remove spaces (ex: "list      sorted")
    args = [arg for arg in args if len(arg) > 0]

    print(args)

    #commands[firstWord]()
    #else:
    #    print("Unknown command given!")

    return commandName, args