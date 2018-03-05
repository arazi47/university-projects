class ArgumentsValidator:
    @staticmethod
    def validate_add_arguments(args):
        id = args[0]
        if not id.isdigit():
            raise Exception("The ID must be a number!")
        elif int(id) < 1:
            raise Exception("The ID must be positive!")

        text = args[1]
        if not len(text) > 0:
            raise Exception("Enter a valid question!")

        choices = [args[2], args[3], args[4]]
        correct_choice = args[5]

        for choice in choices:
            if not len(choice) > 0:
                raise Exception("Enter a valid choice!")

        if not len(correct_choice) > 0:
            raise Exception("Enter a valid correct choice!")

        if not correct_choice in choices:
            raise Exception("The correct choice must be in the choice list!")

        difficulty = args[6]
        if not difficulty in ["easy", "medium", "hard"]:
            raise Exception("Incorrect difficulty entered!")

        return True

    @staticmethod
    def validate_create_quiz(args):
        difficulty = args[0]
        if not difficulty in ["easy", "medium", "hard"]:
            raise Exception("Incorrect difficulty entered!")

        no_of_questions = args[1]
        if not no_of_questions.isdigit():
            raise Exception("The number of questions must be a number!")
        elif int(no_of_questions) < 1:
            raise Exception("The number of questions must be positive!")

        file = args[2]
        if not len(file) > 0:
            raise Exception("The file name is invalid!")

        return True

    @staticmethod
    def validate_start_quiz(args):
        return len(args) > 0