from controllers.questionscontroller import QuestionsController
from validator.questionvalidator import QuestionValidator
from validator.argumentsvalidator import ArgumentsValidator
from repositories.repository import Repository
from domain.question import Question

class RunTests:
    def __init__(self):
        self.__questions_ctrl = QuestionsController()
        self.__repo = Repository()

    def run_questions(self):
        assert self.__questions_ctrl.quiz_questions_args_to_list([[123, "test", "t1", "t2", "t3", "t1", "easy"]])
        assert self.__questions_ctrl.add(["123", "test", "t1", "t2", "t3", "t1", "easy"], True) == True
        assert QuestionValidator.validate_question_id(self.__questions_ctrl.get_all_questions(), 123, []) == False

    def run_repository(self):
        assert self.__repo.size() == 0
        question = Question(123, "test", "t1", "t2", "t3", "t1", "easy")
        self.__repo.add(question)
        assert self.__repo.size() == 1
        assert self.__repo.get_new_list() == [question]
        self.__repo.clear()
        assert self.__repo.size() == 0

    def run_arguments(self):
        assert ArgumentsValidator.validate_create_quiz(["easy", "6", "file.txt"]) == True

        should_be_true = False
        try:
            assert ArgumentsValidator.validate_create_quiz(["asdads", "128", "file.txt"]) == False
        except Exception as e:
            should_be_true = True

        assert should_be_true == True

        assert ArgumentsValidator.validate_add_arguments(["123", "text", "a1", "a2", "a3", "a2", "hard"]) == True
        assert ArgumentsValidator.validate_add_arguments(["1", "iasasaa a a s", "answer 1", "a    2", "a3", "a3", "easy"]) == True
        assert ArgumentsValidator.validate_add_arguments(["1234", "kakkasd??asda?a.sda?", "a1", "a2 3 3", "a3", "a3", "medium"]) == True

        should_be_true = False
        try:
            assert ArgumentsValidator.validate_add_arguments(["123", "text", "a1", "a2", "a3", "a2", "hardz"]) == False
            assert ArgumentsValidator.validate_add_arguments(["93", "spaces s s s s   ss", "a1", "a2", "a3", "a2", "asdaa"]) == True
        except Exception as e:
            should_be_true = True

        assert should_be_true == True

    def run(self):
        self.run_questions()
        self.run_repository()
        self.run_arguments()

        self.__questions_ctrl.clear_repo()