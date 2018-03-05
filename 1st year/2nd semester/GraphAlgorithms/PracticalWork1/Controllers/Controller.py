class Controller:
    def __init__(self, graph, edge_data):
        self.__graph = graph
        self.__edge_data = edge_data

    def return_number_of_vertices(self):
        return self.__graph.get_vertices()

    def return_edge_id_from_vertex_x_to_y(self, start_vertex, end_vertex):
        # TODO get id if true
        if self.__graph.is_edge(start_vertex, end_vertex):
            return True

        return False

        return -1

    def vertex_degree(self, vertex):
        if not self.__graph.exists_vertex(vertex):
            return -1

        return self.__graph.degree_in(vertex), self.__graph.degree_out(vertex)

    def outbound_edges(self, vertex):
        # TODO add some checks, see if the vertex exists

        return self.__graph.outbound(vertex)

    def inbound_edges(self, vertex):
        # TODO add some checks, see if the vertex exists

        return self.__graph.inbound(vertex)

    def endpoints_of_edge_id(self, edge_id):
        # TODO add some checks, see if edge_id exists

        return self.__edge_data.endpoints(edge_id)

    def get_edge_value(self, start_vertex, end_vertex):
        if not self.__graph.is_edge(start_vertex, end_vertex):
            return -1

        return self.__edge_data.get_edge_value(start_vertex, end_vertex)

    def mod_edge_value(self, start_vertex, end_vertex, new_value):
        if not self.__graph.is_edge(start_vertex, end_vertex):
            return False

        return self.__edge_data.mod_edge_value(start_vertex, end_vertex, new_value)
