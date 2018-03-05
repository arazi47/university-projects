class Repository:
    def __init__(self):
        self.__lst = []

    def add(self, obj):
        self.__lst.append(obj)

    def size(self):
        return len(self.__lst)

    def get_new_list(self):
        return self.__lst[:]

    def clear(self):
        self.__lst.clear()
