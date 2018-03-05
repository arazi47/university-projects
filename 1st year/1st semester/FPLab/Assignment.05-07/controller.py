from client import Client
from movie import Movie
from rental import Rental
import datetime


class Controller:
    def __init__(self):
        self.clients = []
        self.movies = []
        self.rentedMovies = []

        self.undoList = []
        self.redoList = []


    def getClients(self):
        return self.clients


    def getMovies(self):
        return self.movies


    def getRentedMovies(self):
        return self.rentedMovies


    def getUndoList(self):
        return self.undoList


    def clearUndoList(self):
        self.undoList.clear()


    def getRedoList(self):
        return self.redoList


    def clearRedoList(self):
        self.redoList.clear()


    # *************************************************** #
    # Movie functions

    def addMovie(self, title, description, genre):
        '''
        :param title: string
        :param description: string
        :param genre: string
        :return: None
        '''

        movie = Movie(len(self.movies) + 1, title, description, genre)
        self.movies.append(movie)

        self.undoList.append(['addMovie', title, description, genre])


    def removeMovie(self, title):
        '''
        :param title: string
        :return: True if the movie with the given name gets removed
                 False otherwise
        '''

        for movie in self.movies:
            if movie.getTitle() == title:
                self.movies.remove(movie)
                self.fixIndices(self.movies)

                self.undoList.append(['removeMovie', title])

                return True

        return False


    def updateMovie(self, oldTitle, newTitle, newDescription, newGenre):
        '''
        :param oldTitle: string
        :param newTitle: string
        :param newDescription: string
        :param newGenre: string
        :return: True if the movie with the given name gets updated
                 False otherwise
        '''

        for movie in self.movies:
            if movie.getTitle() == oldTitle:

                # we also need to store the old description and genre, for redo
                self.undoList.append(['updateMovie', oldTitle, movie.getDescription(), movie.getGenre(), newTitle, newDescription, newGenre])

                movie.setTitle(newTitle)
                movie.setDescription(newDescription)
                movie.setGenre(newGenre)

                return True

        return False


    def searchMovieMatch(self, title):
        '''
        :param name: string
        :return: list of matching names (full match or partial match)
        '''

        outputList = []
        for movie in self.movies:
            if title == movie.getTitle() or title in movie.getTitle():
                outputList.append(movie.getTitle())

        return outputList

    def clearMovies(self):
        self.movies.clear()


    # *************************************************** #
    # Client functions

    def addClient(self, name):
        '''
        :param name: string
        :return: None
        '''

        newClient = Client(len(self.clients) + 1, name)
        self.clients.append(newClient)

        self.undoList.append(['addClient', name])


    def removeClient(self, name):
        '''
        :param name: string
        :return: True if the client with the given name gets removed
                 False otherwise
        '''

        for client in self.clients:
            if client.getName() == name:
                self.clients.remove(client)
                self.fixIndices(self.clients)

                self.undoList.append(['removeClient', name])

                return True

        return False


    def updateName(self, oldName, newName):
        '''
        :param oldName: string
        :param newName: string
        :return: True if the client with the given name gets updated
                 False otherwise
        '''

        for client in self.clients:
            if client.getName() == oldName:
                client.setName(newName)

                self.undoList.append(['updateName', oldName, newName])

                return True

        return False


    def fixIndices(self, lst):
        '''
        :param lst: list - can be either self.clients or self.movies
        :return: None

        The function needs to be called when we are removing a client or a movie,
        because of the way I handle setting the ids of clients/movies.

        steps to reproduce (don't call fixIndices to see the issue):
        add name1, name2, name3
        remove name2
        add name4
        print clients
        '''

        for i in range(len(lst)):
            lst[i].setId(i + 1)


    def searchClientMatch(self, name):
        '''
        :param name: string
        :return: list of matching names (full match or partial match)
        '''

        outputList = []
        for client in self.clients:
            if client.getName() == name or name in client.getName():
                outputList.append(client.getName())

        return outputList

    def getClientIdByName(self, name):
        for client in self.clients:
            if client.getName() == name:
                return client.getId()

        return -1


    def clearClients(self):
        self.clients.clear()


    # *************************************************** #
    # Rental functions

    def addRental(self, movieId, clientId, rentedDate):
        '''
        :param movieId: integer
        :param clientId: integer
        :param rentedDate: datetime
        :return: None
        '''

        rental = Rental(len(self.rentedMovies) + 1, movieId, clientId, rentedDate)

        # mark the movie as rented
        self.movies[movieId - 1].setRented(True)
        self.movies[movieId - 1].setTotalRentalDays(self.movies[movieId - 1].getTotalRentalDays() + 7)

        # add to client rental days
        # 7 - total rental days
        # @todo change the days so that the user says how much they want to rent the movie
        # @todo min 1 day, max 7
        self.clients[clientId - 1].setTotalRentalDays(self.clients[clientId - 1].getTotalRentalDays() + 7)

        self.rentedMovies.append(rental)

        #self.undoList.append(['addRental', movieId, clientId, rentedDate])
        self.undoList.append(['addRental', rental])


    def undoAddRental(self, rental):
        '''
        :param rental: object of class Rental
        :return: None
        '''

        self.rentedMovies.remove(rental)
        self.clients[rental.getClientId() - 1].setTotalRentalDays(self.clients[rental.getClientId() - 1].getTotalRentalDays() - 7)
        self.movies[rental.getMovieId() - 1].setRented(False)
        self.movies[rental.getMovieId() - 1].setTotalRentalDays(self.movies[rental.getMovieId() - 1].getTotalRentalDays() - 7)


    def redoRental(self, rental):
        '''
        :param rental: object of class rental
        :return: None
        '''

        rental.setReturnedDate(-1)
        self.rentedMovies.append(rental)
        self.clients[rental.getClientId() - 1].setTotalRentalDays(self.clients[rental.getClientId() - 1].getTotalRentalDays() + 7)
        self.movies[rental.getMovieId() - 1].setRented(True)
        self.movies[rental.getMovieId() - 1].setTotalRentalDays(self.movies[rental.getMovieId() - 1].getTotalRentalDays() + 7)


    def returnMovie(self, movieId, returnDate):
        '''
        :param movieId: integer
        :return: None
        Set the returned date of the rental of the movie with the specified movieId to today
        '''

        rtl = 0
        for rental in self.rentedMovies:
            if rental.getMovieId() == movieId:
                rental.setReturnedDate(returnDate)

                # the movie is not rented anymore
                self.movies[movieId- 1].setRented(False)

                # actually, we don't want to do that, right?
                # subtract from total client rental days
                #self.clients[rental.getClientId() - 1].setTotalRentalDays(self.clients[rental.getClientId() - 1].getTotalRentalDays() - 7)
                rtl = rental
                break

        self.undoList.append(['returnMovie', movieId, rtl, returnDate])


    def undoReturnMovie(self, rental):
        rental.setReturnedDate(-1)
        self.movies[rental.getMovieId() - 1].setRented(True)


    def getRentalByMovieId(self, movieId):
        '''
        :param movieId: integer
        :return: rental containing the given movieId
                 -1 otherwise
        '''

        for rental in self.rentedMovies:
            if rental.getMovieId() == movieId:
                return rental

        return -1


    # obsolete, most likely we can delete this!
    def isMovieRented(self, movie):
        '''
        :param movie: an object of class Movie
        :return: True if the movie is rented
                 False otherwise
        '''

        for rentedMovie in self.rentedMovies:
            if rentedMovie.getMovieId() == movie.getMovieId():
                return True

        return False


    def clearRentals(self):
        self.rentedMovies.clear()


    # *************************************************** #
    # Misc functions
    def getMostActiveClients(self):
        '''
        :return: The client list sorted in decreasing order by their total rental days
        '''

        sortedClients = self.clients[:]
        sortedClients.sort(key = lambda client: client.getTotalRentalDays(), reverse = True)

        return sortedClients


    def undo(self):
        if len(self.undoList) == 0:
            return

        # get the last element of undoList
        lastCommand = self.undoList[-1]
        if lastCommand[0] == 'addClient':
            self.removeClient(lastCommand[1])
        elif lastCommand[0] == 'removeClient':
            self.addClient(lastCommand[1])
        elif lastCommand[0] == 'addMovie':
            self.removeMovie(lastCommand[1])
        elif lastCommand[0] == 'removeMovie':
            self.addMovie(lastCommand[1], lastCommand[2], lastCommand[3])
        # @todo change this to updateClient(Name)
        elif lastCommand[0] == 'updateName':
            self.updateName(lastCommand[2], lastCommand[1])
        elif lastCommand[0] == 'updateMovie':
            #        0         1         2          3          4          5         6
            # 'updateMovie' oldTitle   oldDesc   oldGenre   newTitle   newDesc   newGenre
            self.updateMovie(lastCommand[4], lastCommand[1], lastCommand[2], lastCommand[3])
        elif lastCommand[0] == 'addRental':
            #self.returnMovie(lastCommand[1], lastCommand[3])
            self.undoAddRental(lastCommand[1])
        elif lastCommand[0] == 'returnMovie':
            self.undoReturnMovie(lastCommand[2])

        # so we can redo the last operation
        self.redoList.append(lastCommand)

        # we're done with this command, let's get rid of it
        self.undoList.pop()


    def redo(self):
        if len(self.redoList) == 0:
            return

        lastCommand = self.redoList[-1]
        if lastCommand[0] == 'addClient':
            self.addClient(lastCommand[1])
        elif lastCommand[0] == 'removeClient':
            self.removeClient(lastCommand[1])
        elif lastCommand[0] == 'addMovie':
            self.addMovie(lastCommand[1], lastCommand[2], lastCommand[3])
        elif lastCommand[0] == 'removeMovie':
            self.removeMovie(lastCommand[1])
        elif lastCommand[0] == 'updateName':
            self.updateName(lastCommand[1], lastCommand[2])
        elif lastCommand[0] == 'updateMovie':
            self.updateMovie(lastCommand[1], lastCommand[4], lastCommand[5], lastCommand[6])
        elif lastCommand[0] == 'addRental':
            # mai trebuie lucrat p-aici
            #self.addRental(lastCommand[1], lastCommand[2], lastCommand[3])
            self.redoRental(lastCommand[1])
        elif lastCommand[0] == 'returnMovie':
            self.returnMovie(lastCommand[1], lastCommand[3])

        self.redoList.pop()
