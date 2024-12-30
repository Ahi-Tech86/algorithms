#include "../../include/algorithms/graph_algorithms.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

pair<vector<int>, int> getPath(vector<bool> visited, vector<int> parent, int goalVertex);

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

    return getPath(visited, parent, goalVertex);
}

pair<vector<int>, int> dfs(vector<vector<int>> adjList, int startVertex, int goalVertex) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    stack<int> stack;

    visited[startVertex] = true;
    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        if (currentVertex == goalVertex) {
            break;
        }

        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = currentVertex;
                stack.push(neighbor);
            }
        }
    }

    return getPath(visited, parent, goalVertex);
}

pair<vector<int>, int> dijkstra(vector<vector<pair<int, int>>> adjList, int startVertex, int goalVertex) {
    using Edge = pair<int, int>;

    int V = adjList.size();
    vector<int> parent(V, -1);
    vector<int> visited(V, false);
    priority_queue<Edge, vector<Edge>, Compare> pq;
    vector<int> dist(V, numeric_limits<int>::max());

    dist[startVertex] = 0;
    pq.push({startVertex, 0});

    while (!pq.empty()) {
        int currentVertex = pq.top().first;
        int currentDist = pq.top().second;
        pq.pop();

        if (visited[currentVertex]) continue;
        visited[currentVertex] = true;

        if (currentVertex == goalVertex) break;

        for (Edge neighbor : adjList[currentVertex]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[currentVertex] + weight < dist[v]) {
                dist[v] = dist[currentVertex] + weight;
                parent[v] = currentVertex;
                pq.push({v, dist[v]});
            }
        }
    }

    vector<int> path;
    for (int at = goalVertex; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    return {path, dist[goalVertex]};
}

pair<vector<int>, int> getPath(vector<bool> visited, vector<int> parent, int goalVertex) {
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

void print_path(vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        if (i == path.size() - 1) {
            cout << path[i];
        } else {
            cout << path[i] << " -> ";
        }
    }
    cout << endl;
}
