class Client:
    def __init__(self, id, name):
        self._id = id
        self._name = name


    def setId(self, id):
        self._id = id


    def getId(self):
        return self._id


    def setName(self, name):
        self._name = name


    def getName(self):
        return self._name