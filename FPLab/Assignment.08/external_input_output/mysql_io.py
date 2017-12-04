import pymysql


class MySQL_IO():
    def __init__(self):
        self.conn = pymysql.connect(host='127.0.0.1', unix_socket='/var/run/mysqld/mysqld.sock', user='root', passwd='root', db='sys', autocommit = True)
        self.cur = self.conn.cursor()


    def readClients(self):
        '''
        :return: A list of lists, each sublist containing the info of a client
        '''

        self.cur.execute('SELECT * FROM Clients')
        return list(self.cur)


    def readMovies(self):
        '''
        :return: A list of lists, each sublist containing the info of a movie
        '''

        self.cur.execute('SELECT * FROM Movies')
        return list(self.cur)


    def readRentals(self):
        '''
        :return: A list of lists, each sublist containing the info of a rental
        '''

        self.cur.execute('SELECT * FROM Rentals')
        return list(self.cur)


    def writeClients(self, clientList):
        '''
        :param clientList: A list of clients (objects of Client)
        :return: None
        '''
        self.cur.execute('truncate Clients')
        for client in clientList:
            self.cur.execute('INSERT INTO Clients (id, name, total_rental_days) VALUES (\'{0}\', \'{1}\', \'{2}\')'.format(client.getId(), client.getName(), client.getTotalRentalDays()))


    def writeMovies(self, movieList):
        '''
        :param clientList: A list of movies (objects of Movie)
        :return: None
        '''
        self.cur.execute('truncate Movies')
        for movie in movieList:

            # cannot pass boolean values
            if movie.isRented:
                rented = 1
            else:
                rented = 0

            self.cur.execute('INSERT INTO Movies (id, title, description, genre, is_rented, total_rental_days) VALUES (\'{0}\', \'{1}\', \'{2}\', \'{3}\', \'{4}\', \'{5}\')'.format(movie.getId(), movie.getTitle(), movie.getDescription(), movie.getGenre(), rented, movie.getTotalRentalDays()))


    def writeRentals(self, rentalList):
        '''
        :param clientList: A list of rentals (objects of Rental)
        :return: None
        '''
        self.cur.execute('truncate Rentals')
        for rental in rentalList:
            self.cur.execute('INSERT INTO Rentals (id, movie_id, client_id, rented_date, due_date, returned_date) VALUES (\'{0}\', \'{1}\', \'{2}\', \'{3}\', \'{4}\', \'{5}\')'.format(rental.getRentalId(), rental.getMovieId(), rental.getClientId(), rental.getRentedDate().strftime('%Y-%m-%d'), rental.getDueDate().strftime('%Y-%m-%d'), rental.getReturnedDate().strftime('%Y-%m-%d')))
