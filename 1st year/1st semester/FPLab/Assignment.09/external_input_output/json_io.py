import json


class JSON_IO():
    def readClients(self):
        '''
        :return: A list of lists, each sublist containing the info of a client
        '''

        try:
            f = open('clients.json', 'r')
            data = []
            for line in f.readlines():
                data.append(json.loads(line))

            f.close()

            return data
        except:
            # file is empty, for example
            return []

    def readMovies(self):
        '''
        :return: A list of lists, each sublist containing the info of a movie
        '''

        try:
            f = open('movies.json', 'r')
            data = []
            for line in f.readlines():
                data.append(json.loads(line))

            f.close()

            return data
        except:
            return []


    def readRentals(self):
        '''
        :return: A list of lists, each sublist containing the info of a rental
        '''

        try:
            f = open('rentals.json', 'r')
            data = []
            for line in f.readlines():
                data.append(json.loads(line))

            f.close()

            return data
        except:
            return []


    def writeClients(self, clientList):
        '''
        :param clientList: A list of clients (objects of Client)
        :return: None
        '''

        f = open('clients.json', 'w')

        for client in clientList:
            cl = [client.getId(), client.getName(), client.getTotalRentalDays()]
            json.dump(cl, f)
            f.write('\n')

        f.close()


    def writeMovies(self, movieList):
        '''
        :param clientList: A list of movies (objects of Movie)
        :return: None
        '''

        f = open('movies.json', 'w')

        for movie in movieList:
            mv = [movie.getId(), movie.getTitle(), movie.getDescription(), movie.getGenre(), movie.isRented(), movie.getTotalRentalDays()]
            json.dump(mv, f)
            f.write('\n')

        f.close()


    def writeRentals(self, rentalList):
        '''
        :param clientList: A list of rentals (objects of Rental)
        :return: None
        '''

        f = open('rentals.json', 'w')

        for rental in rentalList:
            rtl = [rental.getRentalId(), rental.getMovieId(), rental.getClientId(), rental.getRentedDate(), rental.getDueDate(), rental.getReturnedDate()]
            json.dump(rtl, f)
            f.write('\n')

        f.close()
