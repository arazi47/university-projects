from Domain.EdgeProperty import EdgeProperty


class Graph:
    def __init__(self, vertices, edges):
        self.__vertices = vertices
        self.__edges = edges

        self.__dict_in = {}
        self.__dict_out = {}

        for i in range(vertices):
            self.__dict_in[i] = []
            self.__dict_out[i] = []

    def __str__(self):
        print("Directed graph with {} vertices and {} edges.".format(self.__vertices, self.__edges))

    def get_vertices(self):
        return self.__vertices

    def get_edges(self):
        return self.__edges

    def add_edge(self, start_vertex, end_vertex):
        '''
        :param edge: object of class EdgeProperty
        :return: None
        '''

        if start_vertex not in self.__dict_in[end_vertex]:
            self.__dict_in[end_vertex].append(start_vertex)

        if end_vertex not in self.__dict_out[start_vertex]:
            self.__dict_out[start_vertex].append(end_vertex)

    def vertex_exists(self, vertex):
        return vertex >= 0 and vertex < self.__vertices

    def is_edge(self, start_vertex, end_vertex):
        '''
        :param start_vertex: starting vertex
        :param end_vertex:  ending vertex
        :return: True if there exists an edge starting from start_vertex to end_vertex, False otherwise
        '''

        if not self.vertex_exists(start_vertex) or not self.vertex_exists(end_vertex):
            return False

        return end_vertex in self.__dict_out[start_vertex]

    def exists_vertex(self, vertex):
        return vertex in self.__dict_in.keys() and vertex in self.__dict_out.keys()

    def degree_in(self, vertex):
        return len(self.__dict_in[vertex])

    def degree_out(self, vertex):
        return len(self.__dict_out[vertex])

    def outbound(self, vertex):
        return self.__dict_out[vertex]

    def inbound(self, vertex):
        return self.__dict_in[vertex]

