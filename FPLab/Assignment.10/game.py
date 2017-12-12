from board import Board
from utils import Utils
import random

class Game:
    def __init__(self):
        self.__board = Board(6, 6)
        self.__turn = 'X'

    def get_board(self):
        return self.__board

    def get_turn(self):
        return self.__turn

    def make_play(self, coords):
        coords = Utils.parse_coords(coords)

        if coords == False:
            return -1

        if self.__board.is_space_empty(coords):
            self.__board.occupy_space(coords, self.__turn)
            self.__board.occupy_neighbors(coords)
            self.set_other_turn()
        else:
            return -2

    def set_other_turn(self):
        if self.__turn == 'X':
            self.__turn = 'O'
        else:
            self.__turn = 'X'

    def ai_move(self):
        empty_spaces = self.__board.get_empty_spaces()
        #print(empty_spaces)

        result_coords = random.sample(empty_spaces, 1)

        self.make_play(result_coords)

    def check_win(self):
        if self.__board.get_empty_spaces() == []:
            return True

        return False
