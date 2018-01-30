'''
1;which number is the largest;1;4;3;4;easy
2;which number is the smallest;-3;3;0;-3;easy
3;which number is prime;2;32;9;2;easy
4;which country has the largest GPD;Brazil;China;UK;medium
5;which is not a fish;carp;orca;eel;orca;medium
7;which Apollo mission did not make it to the moon;11;13;17;13;hard
8;a mole can be;animal;quantity;both;both;hard
9;name El Cid's horse;Babieca;Abu;Santiago;Babieca;hard
10;the western roman empire fell in;654;546;476;476;hard
'''

from utilities.parser import Parser

class FileController:
    @staticmethod
    def load_questions(file_name):
        '''
        :param file_name: the file name which we will open and load the questions from
        :return: a list of questions, provided as arguments
        '''

        file = open(file_name, "r")

        questions = []
        for line in file.readlines():
            questions.append(Parser.get_arguments(line, ";", True))

        file.close()

        return questions

    @staticmethod
    def create_quiz(file_name, questions):
        '''
        :param file_name: the name of the new quiz we're creating
        :param questions: the list of questions (objects of class Question, which will be converted to arguments)
        :return: None
        '''

        file = open(file_name, "w")
        for question in questions:
            file.write(Parser.question_to_line(question))
            file.write("\n")

        file.close()

    @staticmethod
    def dump_question_to_list(file_name, question):
        '''
        :param file_name: the file name to open and append a question to
        :param question: the question that will be appended to the above referenced file
        :return: None
        '''

        file = open(file_name, "a")
        file.write("\n" + Parser.question_to_line(question))
        file.close()
