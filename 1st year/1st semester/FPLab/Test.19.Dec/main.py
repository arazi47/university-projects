from user_interface.user_interface import UserInterface
from tests.test_dna import TestDNA

def main():
    tester = TestDNA()
    tester.run()

    ui = UserInterface()
    ui.run()

if __name__ == '__main__':
    main()