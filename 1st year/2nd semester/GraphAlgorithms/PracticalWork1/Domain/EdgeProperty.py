class EdgeProperty:
    def __init__(self):
        self.__data = {}

    def add_edge(self, start_vertex, end_vertex, value, id):
        edge_tuple = (start_vertex, end_vertex)

        if edge_tuple not in self.__data.keys():
            self.__data[edge_tuple] = [id, value]

    def get_id(self, start_vertex, end_vertex):
        edge_tuple = (start_vertex, end_vertex)

        if edge_tuple in self.__data.keys():
            return self.__data[edge_tuple][0]

        return -1

    def get_value(self, start_vertex, end_vertex):
        edge_tuple = (start_vertex, end_vertex)

        if edge_tuple in self.__data.keys():
            return self.__data[edge_tuple][1]

        return -1

    def endpoints(self, edge_id):
        for key in self.__data.keys():
            if self.__data[key][0] == edge_id:
                return key[1]

        return -1

    def get_edge_value(self, start_vertex, end_vertex):
        edge_tuple = (start_vertex, end_vertex)

        if edge_tuple in self.__data.keys():
            return self.__data[edge_tuple][1]

        return -1

    def mod_edge_value(self, start_vertex, end_vertex, new_value):
        edge_tuple = (start_vertex, end_vertex)

        if edge_tuple in self.__data.keys():
            self.__data[edge_tuple][1] = new_value
            return True

        return False