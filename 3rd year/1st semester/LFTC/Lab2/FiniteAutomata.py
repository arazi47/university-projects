from Grammar import *

class FiniteAutomata:
    def __init__(self, Q, E, q0, F, S):
        self.Q = Q
        self.E = E
        self.q0 = q0
        self.F = F
        self.S = S

    @staticmethod
    def parse_line(line):
        # Only get what comes after the '='
        return line.strip().split(' ')[2:]

    @staticmethod
    def read_file(file_name):
        with open(file_name) as file:
            Q = FiniteAutomata.parse_line(file.readline())
            E = FiniteAutomata.parse_line(file.readline())
            q0 = FiniteAutomata.parse_line(file.readline())[0]  # Only get the letter
            F = FiniteAutomata.parse_line(file.readline())

            file.readline()  # S =

            # Parse all transitions
            #S = [line.strip() for line in file]
            S = []
            for line in file:
                src = line.strip().split('->')[0].strip().replace('(', '').replace(')', '').split(',')[0]
                route = line.strip().split('->')[0].strip().replace('(', '').replace(')', '').split(',')[1]
                dst = line.strip().split('->')[1].strip()
                S.append(((src, route), dst))

            return FiniteAutomata(Q, E, q0, F, S)

    @staticmethod
    def from_rg(grammar):
        Q = grammar.N + ['K']
        E = grammar.E
        q0 = grammar.S
        F = ['K']

        S = []
        for production in grammar.P:
            state2 = 'K'
            state1, rhs = production
            if state1 == q0 and rhs[0] == 'E':
                F.append(q0)
                continue

            route = rhs[0]

            if len(rhs) == 2:
                state2 = rhs[1]

            S.append(((state1, route), state2))

        return FiniteAutomata(Q, E, q0, F, S)

    def __str__(self):
        return "Q = { " + ', '.join(self.Q) + " }\n" \
                "E = { " + ', '.join(self.E) + " }\n" \
                "q0 = { " + self.q0 + " }\n" \
                "F = { " + ', '.join(self.F) + " }\n" \
                "S = { " + str(self.S) + " }"
