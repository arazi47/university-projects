import re
from spec import *


class Scanner:
    @staticmethod
    def get_tokens_from_line(line):
        token = ''
        index = 0
        while index < len(line):
            if line[index] == '"':
                if token:
                    yield token
                token, index = Scanner.get_string(line, index)
                yield token
                token = ''  # Reset token after we've found a string
            elif Scanner.is_operator(line[index]):
                if token:
                    yield token
                # Check for <=, >= etc (composed operators)
                token, index = Scanner.get_whole_operator(line, index)
                yield token
                token = ''  # Reset token
            elif line[index] in separators:
                if token:
                    yield token
                token, index = line[index], index + 1
                yield token
                token = ''  # Reset token
            else:
                token += line[index]  # Add a new character to the token
                index += 1  # Increase line index
        if token:
            yield token

    @staticmethod
    def is_identifier(token):
        # Combination of numbers, letters and _
        # But the first character must be a letter
        # And the max length allowed for the identifier is 8
        return re.match(r"^[a-zA-Z]([a-zA-Z]|[0-9]|_){,7}$", token) is not None

    @staticmethod
    def is_constant(token):
        # Integer or string between ""
        return re.match('^(0|[+-]?[1-9][0-9]*)$', token) is not None or re.match('^\".*\"$', token) is not None

    @staticmethod
    def is_operator(token):
        # Could also be part of operator
        # e.g. <, <=
        return token in operators

    @staticmethod
    def get_whole_operator(line, i):
        token = ''
        while i < len(line) and Scanner.is_operator(line[i]):
            token += line[i]
            i += 1

        return token, i

    @staticmethod
    def get_string(line, index):
        #print("Line {}, index = {}".format(line, index))
        token = ''
        quotes = 0

        # Get the string from the first quote to the second quote
        while index < len(line) and quotes < 2:
            if line[index] == '"':
                quotes += 1
            token += line[index]
            index += 1

        return token, index
