class NewRepository:
    def __init__(self):
        self.__lst = []
        self.__currIndex = 0
        self.__iterIndex = 0

    def __setitem__(self, key, value):
        if key < len(self.__lst):
            self.__lst[key] = value
        else:
            self.__lst.append(value)

        self.__currIndex += 1

    def __getitem__(self, key):
        return self.__lst[key]

    def __delitem__(self, key):
        self.__lst.pop(key)

    def __next__(self):
        if self.__iterIndex + 1 == len(self.__lst):
            return

        self.__iterIndex += 1
        return self.__lst[self.__iterIndex]

    def __iter__(self):
        return iter(self.__lst)

    def __len__(self):
        return len(self.__lst)

    def get_index(self):
        return self.__currIndex

    def get_data_newlist(self):
        return self.__lst[:]

    def clear(self):
        self.__lst.clear()
