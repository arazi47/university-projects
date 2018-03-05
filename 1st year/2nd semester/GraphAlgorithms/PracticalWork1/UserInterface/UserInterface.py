from Controllers.Controller import Controller
from utils.utils import Utilities


class UserInterface:
    def __init__(self, graph, edge_data):
        self.__controller = Controller(graph, edge_data)

        self.__menu_options = {
            0 : "0. Exit",
            1 : "1. Get the number of vertices",
            2 : "2. Is there an edge from vertex x to vertex y? If yes, print the edge id",
            3 : "3. In degree & out degree of a vertex",
            4 : "4. Iterate through the set of outbound edges of a vertex and print each id",
            5 : "5. Iterate through the set of inbound edges of a vertex and print each id",
            6 : "6. Get the endpoints of an edge specified by an edge id",
            7 : "7. Retrieve the information attached to a specific edge",
            8 : "8. Modify the information attached to a specific edge"
        }

    def print_menu(self):
        for val in self.__menu_options.values():
            print(val)

    def run(self):
        while True:
            self.print_menu()

            option = Utilities.read_integer(">> ")

            if option == 0:
                exit()
            elif option == 1:
                print("The number of vertices of the graph is {}.".format(self.__controller.return_number_of_vertices()))
            elif option == 2:
                x = Utilities.read_integer("First vertex: ")
                y = Utilities.read_integer("Second vertex: ")
                result = self.__controller.return_edge_id_from_vertex_x_to_y(x, y)

                if result == -1:
                    print("Edge starting from vertex {} to {} could not be found!".format(x, y))
                else:
                    print("Edge starting from vertex {} to {} has the id {}.".format(x, y, result))
            elif option == 3:
                vertex = Utilities.read_integer("Vertex: ")
                result = self.__controller.vertex_degree(vertex)

                if result == -1:
                    print("Vertex could not be found!")
                else:
                    print("Degree in: {}; degree out: {}.".format(result[0], result[1]))
            elif option == 4:
                vertex = Utilities.read_integer("Vertex: ")
                result = self.__controller.outbound_edges(vertex)
                print("The outbound edges of vertex {} are: {}.".format(vertex, result))
            elif option == 5:
                vertex = Utilities.read_integer("Vertex: ")
                result = self.__controller.inbound_edges(vertex)
                print("The inbound edges of vertex {} are: {}.".format(vertex, result))
            elif option == 6:
                edge_id = Utilities.read_integer("Edge id: ")
                result = self.__controller.endpoints_of_edge_id(edge_id)

                if result == -1:
                    print("The endpoint with the specified edge id could not be found!")
                else:
                    print("The endpoint with the edge id {} is {}.".format(edge_id, result))
            elif option == 7:
                x = Utilities.read_integer("First vertex: ")
                y = Utilities.read_integer("Second vertex: ")
                result = self.__controller.get_edge_value(x, y)

                if result == -1:
                    print("The edge starting from vertex {} to {} does not exist!".format(x, y))
                else:
                    print("The value of the edge starting from vertex {} to {} is {}.".format(x, y, result))
            elif option == 8:
                x = Utilities.read_integer("First vertex: ")
                y = Utilities.read_integer("Second vertex: ")
                new_value = Utilities.read_integer("New value: ")
                result = self.__controller.mod_edge_value(x, y, new_value)

                if result == False:
                    print("The edge starting from vertex {} to {} does not exist!".format(x, y))
                else:
                    print("The value of the edge starting from vertex {} to {} has been modified!".format(x, y))
            else:
                print("Unknown option entered!")
