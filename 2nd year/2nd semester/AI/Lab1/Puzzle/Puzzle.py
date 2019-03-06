from copy import deepcopy
from filecmp import cmp

class Puzzle:
    final_state = None

    def __init__(self, initial_state, final_state, empty_y, empty_x):
        self.__n = len(initial_state[0])
        self.__initial_state = initial_state
        Puzzle.final_state = final_state
        self.empty_x = empty_y
        self.empty_y = empty_x

    def get_length(self):
        return self.__n

    def get_initial_state(self):
        return self.__initial_state

    @staticmethod
    def get_final_state():
        return Puzzle.final_state

    def get_empty_coords(self):
        return self.empty_x, self.empty_y

    def __eq__(self, other):
        for i in range(self.__n):
            for j in range(self.__n):
                if self.__initial_state[i][j] != other.get_initial_state()[i][j]:
                    return False
        return True

    def __heuristics(self):
        difference = 0
        for i in range(self.__n):
            for j in range(self.__n):
                if self.__initial_state[i][j] != Puzzle.final_state[i][j]:
                    difference += 1
        return difference

    def __lt__(self, other):
        return self.__heuristics() < other.__heuristics()

    def __str__(self):
        result = ""
        for i in range(self.__n):
            result += str(self.__initial_state[i])
            result += "\n"

        return result

    @staticmethod
    def get_empty_spaces_indices(state):
        n = len(state[0])
        for i in range(n):
            for j in range(n):
                if state[i][j] == 'x':
                    return i,j

        return 0,0
