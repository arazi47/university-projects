//
// Created by sysadmin on 31.03.2018.
//

#ifndef GRAFE_LAB2_GRAPH_H
#define GRAFE_LAB2_GRAPH_H

#include <vector>
#include <list>

using namespace std;

class Graph {
    public:
        explicit Graph(unsigned int vertices);
        ~Graph() = default;

        void addEdge(int x, int y, int cost);
        bool isEdge(int x, int y);

        void setVertices(unsigned int v);
        int getVertices();

        void setEdges(unsigned int e);
        int getEdges();

        void BFS(int start);
        void DFSRec(int vertex, vector<bool>& visited);
        void DFS(int start);

    private:
        vector< vector<int> > vEdges;
        unsigned int vertices;
        unsigned int edges;
};


#endif //GRAFE_LAB2_GRAPH_H
