class Utilities:
    @staticmethod
    def read_integer(text):
        while True:
            inp = input(text)

            if not inp.isdigit():
                continue
            else:
                return int(inp)