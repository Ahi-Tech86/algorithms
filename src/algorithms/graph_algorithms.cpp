#include "../../include/algorithms/graph_algorithms.h"
#include <algorithm>
#include <fstream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

pair<vector<int>, int> bfs(vector<vector<int>> adjList, int startVertex, int goalVertex) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        // getting first element
        int currentVertex = q.front();
        // delete element
        q.pop();

        if (startVertex == goalVertex) {
            break;
        }

        // getting all neighbors from current vertex
        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                // setting parent node to neighbor vertex
                parent[neighbor] = currentVertex;
                q.push(neighbor);
            }
        }
    }

    vector<int> path;
    int length = 0;
    if (visited[goalVertex]) {
        // getting path to goal
        // example:
        //  0 -> 1 -> 3 -> 5
        //  parent[5] = 3
        //  parent[3] = 1
        //  parent[1] = 0
        //  parent[0] = -1
        for (int at = goalVertex; at != -1; at = parent[at]) {
            path.push_back(at);
            length++;
        }

        reverse(path.begin(), path.end());
    }

    return {path, length - 1};
}
