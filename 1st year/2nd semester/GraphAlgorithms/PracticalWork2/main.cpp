#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g = Graph(5);
    g.addEdge(0,1, 3);
    g.addEdge(0,2, 5);
    g.addEdge(1,2, 8);
    //g.addEdge(2,0);
    g.addEdge(2, 3, 2);
    //g.addEdge(3,3);
    g.addEdge(3, 4, 1);
    g.BFS(1);
    cout << endl;
    g.DFS(3);
    cout << endl;
    g.shortestPath(0);

    return 0;
}
