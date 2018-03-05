from repositories.repository import Repository
from validator.questionvalidator import QuestionValidator
from domain.question import Question
from controllers.filecontroller import FileController

class QuestionsController:
    def __init__(self):
        self.__repo = Repository()

    def add(self, args, from_file = False):
        '''
        :param args: the 7 arguments of a Questions provided as a list
        :param from_file: if True, when we read the questions from the master question list, we won't dump them again in the file, only if we add the questions from the program
        :return: True, or raises an Exception
        '''

        id = int(args[0])

        if QuestionValidator.validate_question_id(self.__repo.get_new_list(), id, args):
            question = Question(id, args[1], args[2], args[3], args[4], args[5], args[6])
            self.__repo.add(question)

            # Don't dump the same questions again when reading from file
            if not from_file:
                FileController.dump_question_to_list("master_question_list.txt", question)

            return True
        else:
            raise Exception("The ID of the question must be unique!")

    def quiz_questions_args_to_list(self, questions):
        result = []
        for args in questions:
            result.append(Question(int(args[0]), args[1], args[2], args[3], args[4], args[5], args[6]))

        return result

    def add_questions(self, questions):
        '''
        :param questions: Add multiple questions at once, provided as a list of lists of arguments of the class Question
        :return: None
        '''

        for question in questions:
            self.add(question, True)

    def get_questions(self, difficulty, no_of_questions):
        '''
        :param difficulty: the difficulty that we want most of our questions from the quiz to be
        :param no_of_questions: the number of questions the quiz will contain
        :return: the sorted questions list (sorted by difficulty in increasing order)
        '''

        questions_with_needed_difficulty = 0
        question_list = self.__repo.get_new_list()
        quiz_list = []
        i = 0
        while i < len(question_list):
            if question_list[i].get_difficulty() == difficulty:
                questions_with_needed_difficulty += 1

                # append the question to the quiz question list
                quiz_list.append(question_list[i])

                # remove the selected questions from the question list
                question_list.pop(i)

                if len(quiz_list) == no_of_questions:
                    break
            else:
                i += 1

        if questions_with_needed_difficulty < no_of_questions // 2:
            raise Exception("Not enough {0} questions found in the master question list!".format(difficulty))

        if len(quiz_list) == no_of_questions:
            return self.sort_by_difficulty(quiz_list)

        i = 0
        while i < len(question_list):
            quiz_list.append(question_list[i])

            if len(quiz_list) == no_of_questions:
                return self.sort_by_difficulty(quiz_list)

            i += 1

    def sort_by_difficulty(self, questions):
        '''
        :param questions: list of objects of class Question
        :return: the sorted list in increasing order of the difficulty
        '''

        '''
        # mai trebuia return doar?

        for i in range(0, len(questions) - 1):
            for j in range(i + 1 , len(questions)):
                print("i + " + str(i)  + questions[i].get_text())
                print("j + " + str(j) + questions[j].get_text())
                if questions[i].get_difficulty() == "medium" and questions[j].get_difficulty() == "easy":
                    questions[i], questions[j] = questions[j], questions[i]
                elif questions[i].get_difficulty() == "hard" and (questions[j].get_difficulty() == "easy" or questions[j].get_difficulty() == "medium"):
                    questions[i], questions[j] = questions[j], questions[i]
        '''

        # Optimized bubble sort :D
        done = False
        n = len(questions) - 1

        while not done:
            done = True
            for i in range(0, n):
                if questions[i].get_difficulty == "medium" and questions[i + 1].get_difficulty == "easy":
                    questions[i], questions[i + 1] = questions[i + 1], questions[i]
                    done = False
                elif questions[i].get_difficulty() == "hard" and (questions[i + 1].get_difficulty() == "easy" or questions[i + 1].get_difficulty() == "medium"):
                    questions[i], questions[i + 1] = questions[i + 1], questions[i]
                    done = False
            n -= 1

        return questions

    def get_all_questions(self):
        return self.__repo.get_new_list()

    def clear_repo(self):
        self.__repo.clear()