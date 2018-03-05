from utilities.parser import Parser
from validator.argumentsvalidator import ArgumentsValidator
from controllers.questionscontroller import QuestionsController
from controllers.filecontroller import FileController
from domain.quiz import Quiz

class UserInterface:
    def __init__(self, q_ctrl):
        self.__questions_ctrl = q_ctrl
        self.__quiz = Quiz()

    def get_input(self, message):
        inp = input(message)

        return inp

    def run(self):
        while True:
            command  = self.get_input("Enter command: ")
            command_name = Parser.get_command_name(command)

            if command == "exit":
                exit()
            elif command_name == "add":
                add_args = Parser.get_arguments(command, ";")

                try:
                    ArgumentsValidator.validate_add_arguments(add_args)
                    self.__questions_ctrl.add(add_args)
                except Exception as e:
                    print(e)
            elif command_name == "create":
                create_args = Parser.get_arguments(command, " ")

                try:
                    ArgumentsValidator.validate_create_quiz(create_args)
                    quiz_questions = self.__questions_ctrl.get_questions(create_args[0], int(create_args[1]))

                    FileController.create_quiz(create_args[2], quiz_questions)
                except Exception as e:
                    print(e)
            elif command_name == "start":
                start_args = Parser.get_arguments(command, " ")

                try:
                    ArgumentsValidator.validate_start_quiz(start_args)

                    quiz_questions_as_arugments = FileController.load_questions(start_args[0])
                    quiz_questions = self.__questions_ctrl.quiz_questions_args_to_list(quiz_questions_as_arugments)
                    self.__quiz.set_questions(quiz_questions)
                    self.__quiz.start()

                    print("You finished the quiz with a score of {0}!".format(self.__quiz.get_score()))
                except Exception as e:
                    print(e)
            # Debug command
            elif command == "list":
                for q in self.__questions_ctrl.get_all_questions():
                    print(q.get_text())
            else:
                print("Unknown command entered!")
