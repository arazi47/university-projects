class Utils:
    @staticmethod
    def parse_coords(coords):
        '''
        :param coords:
        :return:
        '''

        coords = coords.split()

        try:
            coord_x = int(coords[0])
            coord_y = int(coords[1])

            return coord_x - 1, coord_y - 1
        except:
            return False