from math import sqrt

def readInt(text):
    """
    Function that makes sure we read an integer
    Without crashing the program
    """

    """
    we have to declare option before getting the input
    in case we catch ValueError
    otherwise, the program will crash
    """
    num = -1

    """
    Error comes in handy when reading list values in function readList()
    If it's False, we won't append num to the list
    """
    error = False

    try:
        num = int(input(text))
    except ValueError:
        print("Input is not an integer!")
        error = True

    if error:
        return False

    return num


def readList(lst):
    lst.clear()

    n = readInt("List size: ")
    for i in range(0, n):
        val = readInt("Item " + str(i) + ": ")

        if type(val) == int:
            lst.append(val)
        else:
            return


def printList(lst):
    print(lst)


def printListFromIToJ(lst, startIndex, endIndex):
    """
    Prints lst's elements from startIndex to endIndex
    """
    while startIndex <= endIndex:
        print(lst[startIndex], end=' ')
        startIndex += 1

    # acts as newline
    print()


# prints the longest sequence of increasing numbers
def printLongestIncNumSeq(lst):
    # current sequence start & end index
    iCurr = jCurr = 0

    # maximum sequence start & end index
    iMax = jMax = 0

    # the current index we're at in the list
    i = 0
    while i < len(lst) - 1:
        if lst[i] < lst[i + 1]:
            iCurr = jCurr = i

            # while we have strictly increasing numbers,
            # increase the ending index of the sequence
            while jCurr < len(lst) - 1 and lst[jCurr] < lst[jCurr + 1]:
                print("i is " + str(i) + " and jCurr is " + str(jCurr))
                jCurr = jCurr + 1

            # if the length of the current sequence
            # is bigger than the maximum length
            if jCurr - iCurr > jMax - iMax:
                iMax = iCurr
                jMax = jCurr

            i = jCurr

        i = i + 1

    printListFromIToJ(lst, iMax, jMax)


# prints the longest sequence which contains at most 3 distinct values
def print3DistinctValuesSeq(lst):
    pass


# determines the greatest common divisor of integers a and b
def gcd(a, b):
    while b:
        r = a % b
        a = b
        b = r

    return a


# prints the longest sequence in which all consecutive
# number pairs have the greatest common divisor 1
def printConsecNumPairsHaveGCD1Seq(lst):
    # current sequence start & end index
    iCurr = jCurr = 0

    # maximum length sequence start & end index
    iMax = jMax = 0

    # list index
    i = 0
    while i < len(lst) - 1:
        if gcd(lst[i], lst[i + 1] == 1):
            iCurr = jCurr = i

            while jCurr < len(lst) - 1 and gcd(lst[jCurr], lst[jCurr + 1]) == 1:
                jCurr = jCurr + 1

            if jCurr - iCurr > jMax - iMax:
                iMax = iCurr
                jMax = jCurr

            i = jCurr

        i = i + 1

    printListFromIToJ(lst, iMax, jMax)


def prime(n):
    """
    Returns True if n is a prime number
    False otherwise
    """
    if n < 2:
        return False
    if n % 2 == 0 and n != 2:
        return False

    for d in range(3, int(sqrt(n) + 1), 2):
        if n % d == 0:
            return False

    return True


# prints the longest sequence in which all elements
# are prime numbers
def printPrimeNumSeq(lst):
    # current sequence start & end index
    iCurr = jCurr = 0

    # maximum sequence start & end index
    iMax = jMax = 0

    # current index
    i = 0
    while i < len(lst) - 1:
        if prime(lst[i]):
            iCurr = jCurr = i

            while jCurr < len(lst) - 1 and prime(lst[jCurr + 1]):
                jCurr = jCurr + 1

            if jCurr - iCurr > jMax - iMax:
                iMax = iCurr
                jMax = jCurr

            i = jCurr

        i = i + 1

    printListFromIToJ(lst, iMax, jMax)


def printProperties(lst):
    # printConsecNumPairsHaveGCD1Seq()
    printPrimeNumSeq(lst)


def testPrime():
    """
    Tests the prime algorithm for different values
    """

    assert (prime(-1) == False)
    assert (prime(0) == False)
    assert (prime(1) == False)
    assert (prime(2) == True)
    assert (prime(3) == True)
    assert (prime(9) == False)
    assert (prime(11) == True)


def testGCD():
    """
    Tests the greatest common divisor algorithm for different values
    """

    assert (gcd(2, 5) == 1)
    assert (gcd(4, 8) == 4)
    assert (gcd(14, 35) == 7)


def runTests():
    """
    Runs the tests we have written for the algorithms
    Contained in this program
    """

    testPrime()
    testGCD()


def showMenu(menuOptions):
    for i in menuOptions.values():
        print(i[0])


def menuTest():
    lst = []
    menuOptions = {
        0: ["0. Exit", exit],
        1: ["1. Read list of integers", readList],
        2: ["2. Print the list", printList],
        3: ["3. Print properties #1 and #2", printProperties]
    }

    while True:
        showMenu(menuOptions)
        option = readInt(">> ")

        if option in menuOptions:
            menuOptions[option][1](lst)
        else:
            print("Invalid option selected!")


def menu():
    lst = []

    print("1. Read list of integers")
    print("2. Print the list")
    print("3. Print properties #1 and #2")
    print("4. Exit")

    option = readInt(">> ")

    if option == 1:
        readList(lst)
    elif option == 2:
        printList(lst)
    elif option == 3:
        printProperties(lst)
    elif option == 4:
        exit()
    else:
        print("Uknown option selected!")

    menu()


runTests()
menuTest()
# menu()
