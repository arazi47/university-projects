class Board:
    def __init__(self, board_x, board_y):
        self.__rows = board_x
        self.__columns = board_y
        self.__board = [['_' for x in range(board_x)] for y in range(board_y)]

    def __str__(self):
        board_str = ''

        colNum = [str(i) for i in range(1, len(self.__board[0]) + 1)]
        board_str += '  '
        board_str += str(colNum)
        board_str += '\n'

        rowNum = 1
        for row in self.__board:
            board_str += str(rowNum)
            board_str += ' '
            board_str += str(row)
            board_str += '\n'
            rowNum += 1

        return board_str

    def is_space_empty(self, coords):
        return self.__board[coords[0]][coords[1]] == '_'

    def occupy_space(self, coords, sign):
        print(str(coords))
        print(self.__board[coords[0]][coords[1]])
        self.__board[coords[0]][coords[1]] = sign

    def occupy_neighbors(self, coords):
        pass
