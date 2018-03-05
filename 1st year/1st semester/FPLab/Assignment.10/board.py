class Board:
    def __init__(self, board_x, board_y):
        self.__free_space_sign = '_'
        self.__occupied_space_sign = '#'
        self.__rows = board_x
        self.__columns = board_y
        self.__board = [[self.__free_space_sign for x in range(board_x)] for y in range(board_y)]

    def get_free_space_sign(self):
        return self.__free_space_sign

    def get_occupied_space_sign(self):
        return self.__occupied_space_sign

    def __str__(self):
        board_str = ''

        colNum = [str(i) for i in range(1, len(self.__board[0]) + 1)]
        board_str += '  '
        col_num_str = str(colNum)
        col_num_str = col_num_str.replace(',', '')
        col_num_str = col_num_str.replace('\'', '')
        #board_str += col_num_str

        for char in col_num_str:
            board_str += char
            board_str += ' '

        board_str += '\n'

        rowNum = 1
        for row in self.__board:
            board_str += str(rowNum)
            board_str += '   '
            strRow = str(row)
            strRow = strRow.replace(',', '')
            strRow = strRow.replace('\'', '')
            #board_str += strRow

            for char in row:
                board_str += char
                board_str += '   '

            board_str += '\n'
            rowNum += 1

        return board_str

    def is_space_empty(self, coords):
        return self.__board[coords[0]][coords[1]] == self.__free_space_sign

    def occupy_space(self, coords, sign):
        print(str(coords))
        print(self.__board[coords[0]][coords[1]])
        self.__board[coords[0]][coords[1]] = sign

    def is_within_bounds(self, x, y):
        if y < 0 or y >= self.__rows:
            return False

        if x < 0 or x >= self.__columns:
            return False

        return True

    def occupy_neighbors(self, coords):
        x = coords[0]
        y = coords[1]

        if self.is_within_bounds(x - 1, y - 1):
            self.__board[x - 1][y - 1] = self.__occupied_space_sign

        if self.is_within_bounds(x - 1, y):
            self.__board[x - 1][y] = self.__occupied_space_sign

        if self.is_within_bounds(x - 1, y + 1):
            self.__board[x - 1][y + 1] = self.__occupied_space_sign

        if self.is_within_bounds(x, y - 1):
            self.__board[x][y - 1] = self.__occupied_space_sign

        if self.is_within_bounds(x, y + 1):
            self.__board[x][y + 1] = self.__occupied_space_sign

        if self.is_within_bounds(x + 1, y - 1):
            self.__board[x + 1][y - 1] = self.__occupied_space_sign

        if self.is_within_bounds(x + 1, y):
            self.__board[x + 1][y] = self.__occupied_space_sign

        if self.is_within_bounds(x + 1, y + 1):
            self.__board[x + 1][y + 1] = self.__occupied_space_sign

    def get_empty_spaces(self):
        empty_spaces = []

        for i in range(self.__rows):
            for j in range(self.__columns):
                if self.is_space_empty([i, j]):
                    empty_spaces.append([i, j])

        return empty_spaces


