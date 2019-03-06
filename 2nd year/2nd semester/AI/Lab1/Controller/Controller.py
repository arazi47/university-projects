from queue import PriorityQueue
from copy import deepcopy

from Puzzle.Puzzle import Puzzle


class Controller:
    def __init__(self, puzzle):
        self.__puzzle = puzzle

    def is_solution(self, p):
        return p.get_initial_state() == Puzzle.get_final_state()

    def __expand(self, p):
        di = [-1, 0, 1, 0]
        dj = [0, -1, 0, 1]
        no_of_dirs = len(di)
        children = []
        x, y = p.get_empty_coords()

        for k in range(no_of_dirs):
            if 0 <= x + di[k] < p.get_length() and 0 <= y + dj[k] < p.get_length():
                new_state = deepcopy(p.get_initial_state())
                aux = new_state[x][y]
                new_state[x][y] = new_state[x + di[k]][y + dj[k]]
                new_state[x + di[k]][y + dj[k]] = aux

                free_x = x + di[k]
                free_y = y + dj[k]
                children.append(Puzzle(new_state, p.get_final_state(), free_x, free_y))
        return children

    def bfs(self):
        visited = []
        queue = [[self.__puzzle]]
        while len(queue) > 0:
            steps = queue.pop(0)
            if steps[-1] not in visited:
                visited.append(steps[-1])
            if self.is_solution(steps[-1]):
                return steps
            for p in self.__expand(steps[-1]):
                if p not in visited:
                    steps = steps + [p]
                    if self.is_solution(steps[-1]):
                        return steps
                    visited.append(steps[-1])
                    queue.append(steps)
                    steps = steps[:-1]
        return None

    def gbfs(self):
        visited = []
        queue = PriorityQueue()
        queue.put([self.__puzzle])
        while not queue.empty():
            steps = queue.get()
            if steps[-1] not in visited:
                visited.append(steps[-1])
            if self.is_solution(steps[-1]):
                return steps

            for p in self.__expand(steps[-1]):
                if p not in visited:
                    steps.append(p)
                    visited.append(steps[-1])
                    queue.put(steps)
                    steps = steps[:-1]
        return None
