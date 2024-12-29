#include "../include/structures/graph.h"
#include <vector>

using namespace std;

Graph::Graph(int V) {
    this -> V = V;
    adjList.resize(V);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

void Graph::printGraph() const {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

const vector<vector<int>>& Graph::getAdjList() const {
    return adjList;
}
