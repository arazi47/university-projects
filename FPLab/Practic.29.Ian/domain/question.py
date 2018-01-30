class Question:
    def __init__(self, id, text, choice_a, choice_b, choice_c, correct_choice, difficulty):
        self.__id = id
        self.__text = text
        self.__choice_a = choice_a
        self.__choice_b = choice_b
        self.__choice_c = choice_c
        self.__correct_choice = correct_choice
        self.__difficulty = difficulty

    def get_id(self):
        return self.__id

    def get_text(self):
        return self.__text

    def get_choice_a(self):
        return self.__choice_a

    def get_choice_b(self):
        return self.__choice_b

    def get_choice_c(self):
        return self.__choice_c

    def get_correct_choice(self):
        return self.__correct_choice

    def get_difficulty(self):
        return self.__difficulty