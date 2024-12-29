#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <utility>
#include <vector>

using namespace std;

pair<vector<int>, int> bfs(vector<vector<int>> adjList, int startVertex, int goalVertex);

#endif
