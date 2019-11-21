from FiniteAutomata import *

class Grammar:
    def __init__(self, N, E, P, S):
        self.N = N  # Non-terminals
        self.E = E  # Terminals
        self.P = P  # Productions
        self.S = S  # Starting point

    @staticmethod
    def parse_line(line):
        # Only get what comes after the '='
        return line.strip().split(' ')[2:]

    @staticmethod
    def read_file(file_name):
        with open(file_name) as file:
            N = Grammar.parse_line(file.readline())
            E = Grammar.parse_line(file.readline())
            S = Grammar.parse_line(file.readline())[0]  # Only get the letter

            file.readline()  # P =

            # Parse all productions
            P = []
            for line in file:
                lhs, rhs = line.split('->')
                lhs = lhs.strip()
                rhs = [value.strip() for value in rhs.split('|')]

                for value in rhs:
                    P.append((lhs, value))

            return Grammar(N, E, P, S)

    def is_regular(self):
        """
        S -> aA | bB | X
        A -> aA | cB
        B -> c
        """

        # TODO read this once
        with open('grammar.txt') as file:
            N_unused = Grammar.parse_line(file.readline())
            E_unused = Grammar.parse_line(file.readline())
            S_unused = Grammar.parse_line(file.readline())[0]  # Only get the letter

            file.readline()  # P =

            # Parse all productions
            P = [line.strip() for line in file]

        starting_point_goes_into_epsilon = False
        starting_point_in_rhs = False

        for p in P:
            # Get rhs elements
            for element in p.replace(' ', '')[3:].split('|'):
                if len(element) > 2:
                    return False

                # First element has to be a terminal (or epsilon)
                if element[0] not in self.E and element[0] != 'E':
                    return False

                if element[0] == self.S:
                    starting_point_in_rhs = True

                if len(element) == 2:
                    if element[1] not in self.N:
                        return False

                    if element[1] == self.S:
                        starting_point_in_rhs = True

                # if the starting point goes in Epsilon (E), S cannot be in rhs
                if p[0] == self.S:
                    if element == 'E':
                        starting_point_goes_into_epsilon = True

        if starting_point_goes_into_epsilon and starting_point_in_rhs:
            return False

        return True

    @staticmethod
    def from_fa(fa):
        N = fa.Q
        E = fa.E
        S = fa.q0
        P = []

        # Starting point is final state in FA
        if fa.q0 in fa.F:
            P.append((fa.q0, 'E'))

        for transition in fa.S:
            lhs, state2 = transition
            state1, route = lhs
            print("state1: {} = route {} = state2 {}".format(state1, route, state2))
            P.append((state1, route + state2))

            if state2 in fa.F:
                P.append((state1, route))

        return Grammar(N, E, P, S)

    def __str__(self):
        return "N = { " + ', '.join(self.N) + " }\n" \
                "E = { " + ', '.join(self.E) + " }\n" \
                "P = { " + str(self.P) + " }\n" \
                "S = { " + self.S + " }"
