//
// Created by sysadmin on 31.03.2018.
//

#include "Graph.h"
#include <algorithm>
#include <iostream>

Graph::Graph(unsigned int vertices) {
    this->vEdges.resize(vertices);
}

void Graph::addEdge(int x, int y, int cost) {
    this->vEdges[x].push_back(y);
    this->vEdges[y].push_back(x);
}

bool Graph::isEdge(int x, int y) {
    return find(this->vEdges[x].begin(), this->vEdges[x].end(), y) != this->vEdges[x].end();
}

void Graph::setVertices(unsigned int v) {
    this->vertices = v;
}

int Graph::getVertices() {
    return this->vertices;
}

void Graph::setEdges(unsigned int e) {
    this->edges = e;
}

int Graph::getEdges() {
    return this->edges;
}

/*
 * start (int): starting node
 */

void Graph::BFS(int start) {
    vector<bool> visited(this->vertices);
    for (auto i : visited) {
        visited[i] = false;
    }

    list<int> q;
    visited[start] = true;

    q.push_back(start);
    while (!q.empty()) {
        start = q.front();
        cout << start << ' ';
        q.pop_front();
        for (auto i : this->vEdges[start]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push_back(i);
            }
        }
    }
}

void Graph::DFSRec(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << ' ';

    for (auto i : this->vEdges[vertex]) {
        if (!visited[i]) {
            this->DFSRec(i, visited);
        }
    }
}

/*
 * start (int): starting node
 */

void Graph::DFS(int start) {
    vector<bool> visited(this->vertices);
    for (auto i : visited) {
        visited[i] = false;
    }

    DFSRec(start, visited);
}
