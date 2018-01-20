class Repository:
    def __init__(self):
        self.__adn_list = []

    def append(self, adn_string):
        self.__adn_list.append(adn_string)

    def get_data(self):
        return self.__adn_list

    def length(self):
        return len(self.__adn_list)

    def clear(self):
        self.__adn_list.clear()