import datetime


class UserInterface:
    def __init__(self, utils, ctrl):
        self.utils = utils
        self.ctrl = ctrl

        self.addClients()
        self.addMovies()

        self.menuOptions = {
            0  : "0. Exit",
            1  : "1. Add clients or movies",
            2  : "2. Remove clients or movies",
            3  : "3. Update clients or movies",
            4  : "4. List clients or movies",
            5  : "5. Rent a movie",
            6  : "6. Return a movie",
            7  : "7. Search for clients or movies",
            8  : "8. Statistics",
            9  : "9. Undo",
            10 : "10. Redo",
            11 : "11. Print rental list [DEBUG]",
            12 : "12. Print undo list [DEBUG]",
            13 : "13. Print redo list [DEBUG]"
        }


    def addClients(self):
        self.ctrl.addClient("Aa")
        self.ctrl.addClient("Bb")
        self.ctrl.addClient("Xx")
        self.ctrl.addClient("Hh")
        self.ctrl.addClient("Qz")
        self.ctrl.addClient("Kl")


    def addMovies(self):
        self.ctrl.addMovie("t1", "d1", "g1")
        self.ctrl.addMovie("t2", "d2", "g2")
        self.ctrl.addMovie("t3", "d3", "g3")
        self.ctrl.addMovie("t4", "d4", "g4")
        self.ctrl.addMovie("t5", "d5", "g5")
        self.ctrl.addMovie("t6", "d6", "g6")


    def clientsOrMovies(self):
        '''
        :return: 1 or 2, depending on the input
        '''

        print("1. Client")
        print("2. Movie")

        option = self.utils.readInteger(">> ")
        return option


    def showMenu(self):
        '''
        :return: None

        Prints the menu options
        '''

        for val in self.menuOptions.values():
            print(val)


    def addClient(self):
        '''
        :return: None

        Reads the new client's name, then adds it to the client list
        '''

        name = self.utils.readString("Input name: ")
        self.ctrl.addClient(name)


    def addMovie(self):
        title = self.utils.readString("Input title: ")
        description = self.utils.readString("Input description: ")
        genre = self.utils.readString("Input genre: ")
        self.ctrl.addMovie(title, description, genre)


    def removeClient(self):
        name = self.utils.readString("Input name: ")

        if not self.ctrl.removeClient(name):
            print("Command was not executed.")


    def removeMovie(self):
        title = self.utils.readString("Input title: ")

        if not self.ctrl.removeMovie(title):
            print("Command was not executed.")


    def listClients(self):
        clients = self.ctrl.getClients()
        for client in clients:
            print("[" + str(client.getId()) + " - " + client.getName() + "]")


    def listMovies(self):
        movies = self.ctrl.getMovies()
        for movie in movies:
            print("[" + str(movie.getId()) + " - " + movie.getTitle() + " - " + movie.getDescription() + " - " + movie.getGenre() + "]")


    def rentMovie(self):
        name = self.utils.readString("Who are you? (input name): ")
        result = self.ctrl.searchClientMatch(name)
        if len(result) > 0:
            print("Assuming you are " + result[0] + ". If you are not, please input \"0\" and reenter your correct name! If this is you, enter any other number then press enter to continue")
            tmp = self.utils.readInteger(">> ")
            if tmp == 0:
                return
        else:
            print("Couldn't find your name! Returning.")
            return

        clientId = self.ctrl.getClientIdByName(result[0])

        for rental in self.ctrl.getRentedMovies():
            # if we have previously rented a movie
            if rental.getClientId() == clientId:
                # we have rented a movie, and we have returned it
                if not self.ctrl.getMovies()[rental.getMovieId() - 1].isRented():
                    # if we returned it after its due date, we cannot rent another movie
                    if rental.getReturnedDate() > rental.getDueDate():
                        print("You cannot rent any movie, since you have returned the movie " + self.ctrl.getMovies()[rental.getMovieId() - 1].getTitle() + " after its due date!")
                        return

        # we need this to make sure the user does not enter
        # some invalid movie id
        movieIds = []

        movies = self.ctrl.getMovies()
        for movie in movies:
            if not movie.isRented():
                movieIds.append(movie.getId())
                print("[" + str(movie.getId()) + " - " + movie.getTitle() + " - " + movie.getDescription() + " - " + movie.getGenre() + "]")

        if len(movieIds) == 0:
            print("There are no movies available for renting!")
            return

        option = self.utils.readInteger("Which movie would you like to rent? (input 0 to exit)")

        if option not in movieIds:
            print("Invalid movie id chosen!")
            return

        self.ctrl.addRental(movies[option - 1].getId(), clientId, datetime.datetime.now())


    def returnMovie(self):
        name = self.utils.readString("Who are you? (input name): ")
        result = self.ctrl.searchClientMatch(name)
        if len(result) > 0:
            print("Assuming you are " + result[0] + ". If you are not, please input \"0\" and reenter your correct name! If this is you, enter any other number then press enter to continue")
            tmp = self.utils.readInteger(">> ")
            if tmp == 0:
                return
        else:
            print("Couldn't find your name! Returning.")
            return

        clientId = self.ctrl.getClientIdByName(result[0])

        movieIds = []
        for rental in self.ctrl.getRentedMovies():
            if rental.getClientId() == clientId and not rental.isReturned():
                movie = self.ctrl.getMovies()[rental.getMovieId() - 1]
                movieIds.append(movie.getId())
                print("[" + str(movie.getId()) + " - " + movie.getTitle() + " - " + movie.getDescription() + " - " + movie.getGenre() + "]")

        if len(movieIds) == 0:
            print("You have not rented any movies!")
            return

        option = self.utils.readInteger("Which movie would you like to return? ")

        if option not in movieIds:
            print("Invalid movie id chosen!")
            return

        returnDate = datetime.datetime.today()
        if returnDate > self.ctrl.getRentalByMovieId(option).getDueDate():
            print("Please note that you will not be able to rent any other movies, as you have exceeded the due date for this one!")

        self.ctrl.returnMovie(option, returnDate)


    def updateClient(self):
        oldName = self.utils.readString("Input the name you want to replace: ")
        newName = self.utils.readString("Input new name: ")

        if not self.ctrl.updateName(oldName, newName):
            print("Command was not executed.")

    def updateMovie(self):
        oldTitle = self.utils.readString("Input the title you want to replace: ")
        newTitle = self.utils.readString("Input new title: ")
        newDescription = self.utils.readString("Input new description: ")
        newGenre = self.utils.readString("Input new genre: ")

        if not self.ctrl.updateMovie(oldTitle, newTitle, newDescription, newGenre):
            print("Command was not executed.")


    def searchClient(self):
        name = self.utils.readString("Input name: ")

        result = self.ctrl.searchClientMatch(name)
        if len(result) > 0:
            print(result)
        else:
            print("No matching result found.")


    def searchMovie(self):
        title = self.utils.readString("Input title: ")

        result = self.ctrl.searchMovieMatch(title)
        if len(result) > 0:
            print(result)
        else:
            print("No matching result found")


    def printMostRentedMovies(self):
        if len(self.ctrl.getRentedMovies()) == 0:
            print("There are no rented movies!")
        else:
            print("Most rented movies: ")
            # @todo move this sort out of UI
            movs = self.ctrl.getMovies()
            movs.sort(key = lambda mov: mov.getTotalRentalDays(), reverse = True)
            for movie in movs:
                print("[" + str(
                    movie.getId()) + " - " + movie.getTitle() + " - " + movie.getDescription() + " - " + movie.getGenre() + "]")


    def printRentedMovies(self):
        if len(self.ctrl.getRentedMovies()) == 0:
            print("There are no rented movies!")
        else:
            print("Rented movies: ")
            for rental in self.ctrl.getRentedMovies():
                print(self.ctrl.getMovies()[rental.getMovieId() - 1].getTitle() + " rented by " + self.ctrl.getClients()[rental.getClientId() - 1].getName())


    def printMostActiveClients(self):
        mac = self.ctrl.getMostActiveClients()

        for client in mac:
            print("[" + str(client.getId()) + " - " + client.getName() + " - Total rental days: " + str(client.getTotalRentalDays()) + "]")


    def showStatistics(self):
        self.printMostRentedMovies()
        self.printMostActiveClients()
        self.printRentedMovies()


    def undo(self):
        # undo list is empty
        if not self.ctrl.getUndoList():
            print("There is no command to undo!")
            return

        self.ctrl.undo()


    def redo(self):
        if not self.ctrl.getRedoList():
            print("There is no command to redo!")
            return

        self.ctrl.redo()


    def printRentalList(self):
        rlist = self.ctrl.getRentedMovies()
        for rental in rlist:
            print("Rental id: " + str(rental.getRentalId()) + " - movie id: " + str(rental.getMovieId()) + " - client id: " + str(rental.getClientId()) + " - rented date: "  + str(rental.getRentedDate()) + " - due date: " + str(rental.getDueDate()) + " - returned date: " + str(rental.getReturnedDate()))

    def printUndoList(self):
        print(self.ctrl.getUndoList())


    def printRedoList(self):
        print(self.ctrl.getRedoList())


    def run(self):
        while True:
            self.showMenu()
            option = self.utils.readInteger(">> ")

            '''
            if option in self.menuOptions.keys():
                list(self.menuOptions.values())[option][1]()
            else:
                print("Unknown option!")
            '''

            if option == 0:
                exit()

            elif option == 1:
                clientOrMovie = self.clientsOrMovies()

                if clientOrMovie == 1:
                    self.addClient()
                elif clientOrMovie == 2:
                    self.addMovie()
                else:
                    print("Invalid input!")

            elif option == 2:
                clientOrMovie = self.clientsOrMovies()

                if clientOrMovie == 1:
                    self.removeClient()
                elif clientOrMovie == 2:
                    self.removeMovie()
                else:
                    print("Invalid input!")

            elif option == 3:
                clientOrMovie = self.clientsOrMovies()

                if clientOrMovie == 1:
                    self.updateClient()
                elif clientOrMovie == 2:
                    self.updateMovie()
                else:
                    print("Invalid input")

            elif option == 4:
                clientOrMovie = self.clientsOrMovies()

                if clientOrMovie == 1:
                    self.listClients()
                elif clientOrMovie == 2:
                    self.listMovies()

            elif option == 5:
                self.rentMovie()

            elif option == 6:
                self.returnMovie()

            elif option == 7:
                clientOrMovie = self.clientsOrMovies()

                if clientOrMovie == 1:
                    self.searchClient()
                elif clientOrMovie == 2:
                    self.searchMovie()
                else:
                    print("Invalid input")

            elif option == 8:
                self.showStatistics()
            elif option == 9:
                self.undo()
            elif option == 10:
                self.redo()
            elif option == 11:
                self.printRentalList()
            elif option == 12:
                self.printUndoList()
            elif option == 13:
                self.printRedoList()
            else:
                print("Unknown option!")
