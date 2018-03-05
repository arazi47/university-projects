class Utils:
    @staticmethod
    def parse_coords(coords):
        '''
        :param coords:
        :return:
        '''

        if type(coords) != str:
            return coords[0][0], coords[0][1]

        coords = coords.split()

        try:
            coord_x = int(coords[0])
            coord_y = int(coords[1])

            return coord_x - 1, coord_y - 1
        except Exception as e:
            print(e)
            return False