from Grammar import *
from FiniteAutomata import *


def print_menu():
    print("0. Exit")
    print("1. Read grammar from file")
    print("2. Read grammar from keyboard")
    print("3. Display grammar elements")
    print("4. Check if grammar is regular")
    print("5. Read FA elements from file")
    print("6. Read FA elements from keyboard")
    print("7. Display FA elements")
    print("8. RG -> FA")
    print("9. FA -> RG")


def read_grammar_from_keyboard():
    N = input("Nonterminals: ").split()
    E = input("Terminals: ").split()
    S = input("Starting point: ")
    P = []
    i = 1
    print("Productions (end with 'x'): ")
    while True:
        inp = input("Production {}: ".format(i)).strip()
        if inp == 'x':
            break
        else:
            P.append(inp)
            i += 1

    return Grammar(N, E, P, S)


def read_fa_from_keyboard():
    Q = input("Q: ").split()
    E = input("E: ").split()
    q0 = input("q0: ").split()
    F = input("F: ").split()
    S = []
    i = 1
    print("Transitions (end with 'x'): ")
    while True:
        inp = input("Transition {}: ".format(i)).strip()
        if inp == 'x':
            break
        else:
            src = inp.split('->')[0].strip().replace('(', '').replace(')', '').split(',')[0]
            route = inp.split('->')[0].strip().replace('(', '').replace(')', '').split(',')[1]
            dst = inp.split('->')[1].strip()
            S.append(((src, route), dst))
            i += 1
            print("S is now {}".format(S))

    return FiniteAutomata(Q, E, q0, F, S)


def main():
    grammar = None
    fa = None
    while True:
        print_menu()
        inp = int(input(">> "))
        if inp == 0:
            exit(0)
        elif inp == 1:
            grammar = Grammar.read_file("grammar.txt")
        elif inp == 2:
            grammar = read_grammar_from_keyboard()
        elif inp == 3:
            if grammar:
                print(grammar)
            else:
                print("You must read a grammar first!")
        elif inp == 4:
            if grammar.is_regular():
                print("Regular!")
            else:
                print("Not regular!")
        elif inp == 5:
            fa = FiniteAutomata.read_file("finiteautomata.txt")
        elif inp == 6:
            fa = read_fa_from_keyboard()
        elif inp == 7:
            if fa:
                print(fa)
            else:
                print("You must read a finite automata first!")
        elif inp == 8:
            if grammar:
                fa_from_rg = FiniteAutomata.from_rg(grammar)
                print(fa_from_rg)
            else:
                print("You must read a grammar first!")
        elif inp == 9:
            if fa:
                rg_from_fa = Grammar.from_fa(fa)
                print(rg_from_fa)
            else:
                print("You must read a finite automata first!")
        else:
            print("Invalid input!")

        print("\n\n")


if __name__ == '__main__':
    main()
