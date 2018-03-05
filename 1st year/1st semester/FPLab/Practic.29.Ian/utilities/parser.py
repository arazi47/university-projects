class Parser:
    @staticmethod
    def get_command_name(command):
        if command.find(" ") != -1:
            return command[:command.find(" ")]

        return ""

    @staticmethod
    def get_arguments(command, separator, from_file = False):
        # Eliminate the command name
        # We don't need this when reading from file
        if not from_file:
            command = command[command.find(" ") + 1:]

        args = []
        # This will get all the arguments except the last one
        while command.find(separator) != -1:
            next_arg = command[:command.find(separator)]
            command = command[command.find(separator) + 1:]
            args.append(next_arg)

        # Append the last argument to the list

        if from_file:
            # Hack fix when reading from file
            if command == "easy\n":
                command = "easy"
            elif command == "medium\n":
                command = "medium"
            elif command == "hard\n":
                command = "hard"

        args.append(command)

        return args

    @staticmethod
    def question_to_line(question):
        return "{0};{1};{2};{3};{4};{5};{6}".format(str(question.get_id()), question.get_text(), question.get_choice_a(), question.get_choice_b(), question.get_choice_c(), question.get_correct_choice(), question.get_difficulty())
