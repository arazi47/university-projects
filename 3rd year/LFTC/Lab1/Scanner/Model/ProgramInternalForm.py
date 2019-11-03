class ProgramInternalForm:
    def __init__(self):
        self.__data = []

    def add(self, codification_table_id, guid):
        self.__data.append((codification_table_id, guid))

    def __str__(self):
        return str(self.__data)

    def get_data(self):
        return self.__data
