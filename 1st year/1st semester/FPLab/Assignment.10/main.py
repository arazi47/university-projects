from user_interface import UserInterface
from game import Game

def main():
    game = Game()
    ui = UserInterface(game)

    ui.run_game()

if __name__ == '__main__':
    main()