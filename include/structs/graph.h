#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printGraph() const;
    const vector<vector<int>>& getAdjList() const;
};

#endif
