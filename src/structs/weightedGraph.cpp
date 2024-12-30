#include "../../include/structures/weightedGraph.h"
#include <ostream>
#include <vector>

using namespace std;

WeightedGraph::WeightedGraph(int V) {
    this -> V = V;
    adjList.resize(V);
}

void WeightedGraph::addEdge(int v, int w, int weight) {
    adjList[v].emplace_back(w, weight);
    adjList[w].emplace_back(v, weight);
}

void WeightedGraph::printGraph() const {
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";
        for (const auto& edge : adjList[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}

const vector<vector<pair<int, int>>>& WeightedGraph::getAdjList() const {
    return adjList;
}
