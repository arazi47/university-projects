class Quiz:
    def __init__(self):
        self.__score = 0
        self.__questions = []

    def set_questions(self, questions):
        self.__questions = questions

    def get_score(self):
        return self.__score


    def start(self):
        for question in self.__questions:
            print(question.get_text())
            print("Answers {0}, {1}, {2}".format(question.get_choice_a(), question.get_choice_b(), question.get_choice_c()))

            while True:
                inp = input("Answer: ")

                if inp not in [question.get_choice_a(), question.get_choice_b(), question.get_choice_c()]:
                    print("Your answer must be either {0}, {1}, or {2}!".format(question.get_choice_a(), question.get_choice_b(), question.get_choice_c()))
                else:
                    if inp == question.get_correct_choice():
                        if question.get_difficulty() == "easy":
                            self.__score += 1
                        elif question.get_difficulty() == "medium":
                            self.__score += 2
                        else:
                            self.__score += 3

                break
