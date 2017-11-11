class Movie:
    def __init__(self, id, title, description, genre):
        self._id = id
        self._title = title
        self._description = description
        self._genre = genre
        self._isRented = False


    def setId(self, id):
        self._id = id


    def getId(self):
        return self._id


    def setTitle(self, title):
        self._title = title


    def getTitle(self):
        return self._title


    def setDescription(self, description):
        self._description = description


    def getDescription(self):
        return self._description


    def setGenre(self, genre):
        self._genre = genre


    def getGenre(self):
        return self._genre


    def setRented(self, isRented):
        self._isRented = isRented


    def isRented(self):
        return self._isRented