class SymbolTable:
    def __init__(self):
        self.__symTable = []

    def exists(self, identifier_or_constant):
        return identifier_or_constant in self.__symTable

    # This should return id or add + return id
    def add(self, identifier_or_constant):
        guid = self.get_guid_by_symbol(identifier_or_constant)
        if guid != -1:
            return guid

        self.__symTable.append((identifier_or_constant, len(self.__symTable)))
        self.__symTable.sort(key=lambda pair: pair[0])
        # -1 because the length increased by one when we appended the new value to the list
        return len(self.__symTable) - 1

        # Not a good implementation because we lose the index when we sort this
        '''
        if self.exists(identifier_or_constant):
            return self.__symTable.index(identifier_or_constant)

        self.__symTable.append(identifier_or_constant)
        self.__symTable.sort()
        return self.__symTable.index(identifier_or_constant)
        '''

    def __str__(self):
        return str(self.__symTable)

    def get_guid_by_symbol(self, symbol):
        for pair in self.__symTable:
            if pair[0] == symbol:
                return pair[1]

        return -1
