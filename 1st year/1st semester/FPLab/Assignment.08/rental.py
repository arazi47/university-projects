import datetime


class Rental:
    def __init__(self, rentalId, movieId, clientId, rentedDate):
        self._rentalId = rentalId
        self._movieId = movieId
        self._clientId = clientId

        # @todo datetime, not string!
        self._rentedDate = rentedDate
        self._dueDate = rentedDate + datetime.timedelta(days = 7)

        # -1 if the movie has not been returned
        self._returnedDate = rentedDate - datetime.timedelta(days = 1)


    def setRentalId(self, rentalId):
        self.rentalId = rentalId


    def getRentalId(self):
        return self._rentalId


    def setMovieId(self, movieId):
        self._movieId = movieId


    def getMovieId(self):
        return self._movieId


    def setClientId(self, clientId):
        self._clientId = clientId


    def getClientId(self):
        return self._clientId


    def setRentedDate(self, rentedDate):
        self._rentedDate = rentedDate


    def getRentedDate(self):
        return self._rentedDate


    def setDueDate(self, dueDate):
        self._dueDate = dueDate


    def getDueDate(self):
        return self._dueDate


    def setReturnedDate(self, returnedDate):
        self._returnedDate = returnedDate


    def getReturnedDate(self):
        return self._returnedDate


    def isReturned(self):
        return self._returnedDate != -1