#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class WeightedGraph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;
public:
    WeightedGraph(int V);
    void addEdge(int v, int w, int weight);
    void printGraph() const;
    const vector<vector<pair<int, int>>>& getAdjList() const;
};

#endif
