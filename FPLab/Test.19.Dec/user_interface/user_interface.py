from controller.controller import Controller

class UserInterface:
    def __init__(self):
        self.__ctrl = Controller()

    def print_menu(self):
        print('0. Exit')
        print('1. Add DNA')
        print('2. Filter DNA')
        print('3. Nu stiu ce scrie pe tabla da stiu ce face')

    def run(self):
        while True:
            self.print_menu()

            inp = input('>> ')
            if inp == '0':
                exit()
            elif inp == '1':
                dna_string = input('Input DNA sequence: ')
                if not self.__ctrl.add_dna(dna_string):
                    print('Invalid DNA sequence entered')
            elif inp == '2':
                dna_substring = input('Input DNA subsequence: ')
                filtered_dna_list = self.__ctrl.filter_dna_by_subseq(dna_substring)
                print(filtered_dna_list)
            elif inp == '3':
                filtered_dna_list = self.__ctrl.filter_punct3()
                print(filtered_dna_list)
            else:
                print('Invalid command entered!')
