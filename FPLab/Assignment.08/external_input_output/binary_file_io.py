import pickle


class Binary_File_IO():
    def readClients(self):
        '''
        :return: A list of lists, each sublist containing the info of a client
        '''

        try:
            f = open('clients.pickle', 'rb')
            return pickle.load(f)
        except EOFError:
            # we get here if the file is empty
            return []


    def readMovies(self):
        '''
        :return: A list of lists, each sublist containing the info of a movie
        '''

        try:
            f = open('movies.pickle', 'rb')
            return pickle.load(f)
        except EOFError:
            return []


    def readRentals(self):
        '''
        :return: A list of lists, each sublist containing the info of a rental
        '''

        try:
            f = open('rentals.pickle', 'rb')
            return pickle.load(f)
        except EOFError:
            return []


    def writeClients(self, clientList):
        '''
        :param clientList: A list of clients (objects of Client)
        :return: None
        '''

        f = open('clients.pickle', 'wb')
        pickle.dump(clientList, f)
        f.close()


    def writeMovies(self, movieList):
        '''
        :param clientList: A list of movies (objects of Movie)
        :return: None
        '''

        f = open('movies.pickle', 'wb')
        pickle.dump(movieList, f)
        f.close()


    def writeRentals(self, rentalList):
        '''
        :param clientList: A list of rentals (objects of Rental)
        :return: None
        '''

        f = open('rentals.pickle', 'wb')
        pickle.dump(rentalList, f)
        f.close()
