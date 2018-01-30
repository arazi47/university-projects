class QuestionValidator:
    @staticmethod
    def validate_question_id(questions, new_question_id, args):
        for question in questions:
            if question.get_id() == new_question_id:
                return False

        if len(args) != 7:
            return False

        return True
