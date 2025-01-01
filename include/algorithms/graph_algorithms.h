#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <utility>
#include <vector>

using namespace std;

void print_path(vector<int> path);
pair<vector<int>, int> bfs(vector<vector<int>> adjList, int startVertex, int goalVertex);
pair<vector<int>, int> dfs(vector<vector<int>> adjList, int startVertex, int goalVertex);
pair<vector<int>, int> dijkstra(vector<vector<pair<int, int>>> adjList, int startVertex, int goalVertex);
pair<vector<int>, int> bellman_ford(vector<vector<pair<int, int>>> adjList, int start_vertex, int goal_vertex);

#endif
