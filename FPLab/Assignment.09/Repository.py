class Repository:
    def __init__(self):
        self.__lst = []

    def add(self, val):
        self.__lst.append(val)

    def find_by_index(self, index):
        return self.__lst[index]

    def remove_by_index(self, index):
        self.__lst.pop(index)

    def __len__(self):
        return len(self.__lst)

    def get_data(self):
        return self.__lst

    def get_data_newlist(self):
        return self.__lst[:]

    def clear(self):
        self.__lst.clear()
