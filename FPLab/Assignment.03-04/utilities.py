'''
This module contains functions that help the main program, but are not part of what we need to output
'''

def checkScores(score1, score2, score3):
    '''
    Check if scores are within range (>= 0 and <= 10)
    '''

    assert (score1 >= 0 and score1 <= 10 and
            score2 >= 0 and score2 <= 10 and
            score3 >= 0 and score3 <= 10)

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
    # second case example: "add score1, score2, score3
    else:
        args = args.split(',')

    for i in range(len(args)):
        args[i] = args[i].strip(' ')

    # for the first case "remove 1 to 3"
    # arguments would be ['', '1', 'to', '3']
    # we need to remove the ''
    if cmd.find(',') == -1:
        args.pop(0)

    #commands[firstWord]()
    #else:
    #    print("Unknown command given!")

    return commandName, args