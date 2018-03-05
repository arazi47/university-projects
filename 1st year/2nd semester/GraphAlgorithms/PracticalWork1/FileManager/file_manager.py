from Domain.EdgeProperty import EdgeProperty
from Domain.Graph import Graph


class FileManager:
    @staticmethod
    def read_input(data_file_name):
        with open(data_file_name, 'r') as f:
            line = f.readline().split()
            n = int(line[0]) # vertices
            m = int(line[1]) # edges

            edge_data = EdgeProperty()
            graph = Graph(n, m)

            edge_id = 0
            #print(f.readlines())
            for line in f.readlines():
                line = line.split()
                graph.add_edge(int(line[0]), int(line[1]))
                edge_data.add_edge(int(line[0]), int(line[1]), int(line[2]), edge_id)
                edge_id += 1

            return graph, edge_data

        return False
