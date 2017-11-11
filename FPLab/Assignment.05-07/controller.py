from client import Client
from movie import Movie
from rental import Rental

class Controller:
    def __init__(self):
        self.clients = []
        self.movies = []
        self.rentedMovies = []


    def getClients(self):
        return self.clients


    def getMovies(self):
        return self.movies


    def getRentedMovies(self):
        return self.rentedMovies


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


    # *************************************************** #
    # Client functions

    def addClient(self, name):
        '''
        :param name: string
        :return: None
        '''

        newClient = Client(len(self.clients) + 1, name)
        self.clients.append(newClient)


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
        # @todo change name == ... to client.getName() == ... (reverse order)
        for client in self.clients:
            if name == client.getName() or name in client.getName():
                outputList.append(client.getName())

        return outputList

    def getClientIdByName(self, name):
        for client in self.clients:
            if client.getName() == name:
                return client.getId()

        return -1


    # *************************************************** #
    # Rental functions

    def addRental(self, movieId, clientId, rentedDate):
        rental = Rental(len(self.rentedMovies) + 1, movieId, clientId, rentedDate)

        # woop, we rented a movie
        self.movies[movieId - 1].setRented(True)

        self.rentedMovies.append(rental)

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
