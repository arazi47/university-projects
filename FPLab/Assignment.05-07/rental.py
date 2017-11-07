import datetime


class Rental:
    def __init__(self, rentalId, movieId, clientId, rentedDate, returnedDate):
        _rentalId = rentalId
        _movieId = movieId
        _clientId = clientId

        # @todo datetime, not string!
        _rentedDate = rentedDate
        _dueDate = returnedDate

        # -1 if the movie has not been returned
        _returnedDate = -1


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


    def getDuteDate(self):
        return self._dueDate


    def setReturnedDate(self, returnedDate):
        self._returnedDate = returnedDate


    def getReturnedDate(self):
        return self._returnedDate
