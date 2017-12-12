from game import Game

class UserInterface:
    def __init__(self, game):
        self.__game = game

    def run_game(self):
        while True:
            print(self.__game.get_board())

            print('It\'s {0}\'s turn'.format(self.__game.get_turn()))
            print('Input row and column (cannot place on \'!\': ')
            inp = input('>> ')

            result = self.__game.make_play(inp)

            if result == -1:
                print('Invalid coordinates!')
            elif result == -2:
                print('Space is not empty!')
