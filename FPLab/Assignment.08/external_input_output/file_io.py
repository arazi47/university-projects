import datetime


class File_IO():
    def readClients(self):
        '''
        :return: A list of lists, each sublist containing the info of a client
        '''

        f = open('clients.txt', 'r')
        data = f.readlines()
        clientList = []
        for line in data:
            line.strip()
            line = line.replace('\n', '')
            clientList.append(line.split(';'))


        return clientList


    def readMovies(self):
        '''
        :return: A list of lists, each sublist containing the info of a movie
        '''

        f = open('movies.txt', 'r')
        data = f.readlines()
        movieList = []
        for line in data:
            line.lstrip()
            line = line.replace('\n', '')
            movieList.append(line.split(';'))

        return movieList


    def readRentals(self):
        '''
        :return: A list of lists, each sublist containing the info of a rental
        '''

        f = open('rentals.txt', 'r')
        data = f.readlines()
        rentalList = []
        for line in data:
            line.lstrip()
            line = line.replace('\n', '')
            line = line.split(';')

            # 3, 4, 5 => datetime
            for i in range(3, 6):
                date = line[i].split('-')
                line[i] = datetime.datetime(int(date[0]), int(date[1]), int(date[2]))

            rentalList.append(line)

        return rentalList


    def writeClients(self, clientList):
        '''
        :param clientList: A list of clients (objects of Client)
        :return: None
        '''

        f = open('clients.txt', 'w')
        for client in clientList:
            f.write(str(client.getId()) + ';' + client.getName() + '\n')


    def writeMovies(self, movieList):
        '''
        :param clientList: A list of movies (objects of Movie)
        :return: None
        '''

        f = open('movies.txt', 'w')
        for movie in movieList:
            f.write(str(movie.getId()) + ';' + movie.getTitle() + ';' + movie.getDescription() + ';' + movie.getGenre() + '\n')


    def writeRentals(self, rentalList):
        '''
        :param clientList: A list of rentals (objects of Rental)
        :return: None
        '''

        f = open('rentals.txt', 'w')
        for rental in rentalList:
            f.write(str(rental.getRentalId()) + ';' + str(rental.getMovieId()) + ';' + str(rental.getClientId()) + ';' + str(rental.getRentedDate().strftime('%Y-%m-%d')) + ';' + str(rental.getDueDate().strftime('%Y-%m-%d')) + ';' + str(rental.getReturnedDate().strftime('%Y-%m-%d')) + '\n')
