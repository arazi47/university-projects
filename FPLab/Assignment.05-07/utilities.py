import datetime


class Utilities:
    def stringIsInt(self, strData):
        return strData.isdigit()


    def readInteger(self, text):
        while True:
            try:
                inputData = input(text)
                assert self.stringIsInt(inputData) == True
                return int(inputData)
            except AssertionError:
                pass

    def readString(self, text):
        inputData = input(text)

        return inputData.lstrip()