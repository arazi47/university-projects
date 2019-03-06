from Controller.Controller import Controller
from FileManager.FileManager import FileManager
from Puzzle.Puzzle import Puzzle

class View:
    def __init__(self):
        states = FileManager.read_puzzle()
        free_x,free_y = Puzzle.get_empty_spaces_indices(states[0])
        self.__controller = Controller(Puzzle(states[0], states[1], free_x, free_y))

    def print_menu(self):
        print("\t1. Solve using BFS")
        print("\t2. Solve using GBFS")
        print("\t3. Exit")

    def run(self):
        while True:
            self.print_menu()

            option = int(input(">>> "))

            steps = None
            if option == 1:
                steps = self.__controller.bfs()
            elif option == 2:
                steps = self.__controller.gbfs()
            elif option == 3:
                exit(0)
            else:
                print("Invalid input!")

            if option == 1 or option == 2:
                if not steps:
                    print("Nope")
                else:
                    for step in steps:
                        print(step)
                    print()
