from game import Game

class UserInterface:
    def __init__(self, game):
        self.__game = game

    def run_game(self):
        while True:
            print(self.__game.get_board())


            turn = self.__game.get_turn()
            print('It\'s {0}\'s turn'.format(turn))

            if turn == 'X':
                print('Input row and column (cannot place on \'{0}\': '.format(self.__game.get_board().get_occupied_space_sign()))
                inp = input('>> ')

                result = self.__game.make_play(inp)

                if result == -1:
                    print('Invalid coordinates!')
                elif result == -2:
                    print('Space is not empty!')
            else:
                self.__game.ai_move()

            if self.__game.check_win():
                self.__game.set_other_turn()
                print("WE HAVE A WINNER: {0}".format(self.__game.get_turn()))
                return
