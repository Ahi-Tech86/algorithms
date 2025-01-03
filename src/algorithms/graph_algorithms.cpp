#include "../../include/algorithms/graph_algorithms.h"
#include <unordered_map>
#include <functional>
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

pair<vector<int>, int> bellman_ford(vector<vector<pair<int, int>>> adjList, int start_vertex, int goal_vertex) {
    int V = adjList.size();
    vector<int> parent(V, -1);
    vector<int> distance(V, numeric_limits<int>::max());
    
    distance[start_vertex] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                throw runtime_error("Graph contains a negative weight cycle");
            }
        }
    }

    vector<int> path;
    for (int v = goal_vertex; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    if (path.front() != start_vertex) {
        throw runtime_error("No path from start to goal vertex");
    }

    int path_length = distance[goal_vertex];
    
    return {path, path_length};
}

pair<vector<int>, int> a_star(vector<vector<pair<int, int>>> adjList, int start_vertex, int goal_vertex) {
    int V = adjList.size();

    // first cost, second vertex
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    unordered_map<int, int> cost;
    unordered_map<int, int> cameFrom;

    auto heuristic = [](int vertex, int goal) {
        return abs(vertex - goal);
    };

    for (int i = 0; i < V; i++) {
        cost[i] = numeric_limits<int>::max();
    }
    cost[start_vertex] = 0;
    pq.emplace(0, start_vertex);

    while (!pq.empty()) {
        int current_vertex = pq.top().second;
        int current_cost = pq.top().first;
        pq.pop();

        if (goal_vertex == current_vertex) {
            vector<int> path;
            int path_Length = 0;

            for (int at = goal_vertex; at != start_vertex; at = cameFrom[at]) {
                path.push_back(at);
                path_Length += cost[at] - cost[cameFrom[at]];
            }
            path.push_back(start_vertex);
            reverse(path.begin(), path.end());
            return {path, path_Length};
        }
        
        for (const auto& edge : adjList[current_vertex]) {
            int next_vertex = edge.first;
            int edge_cost = edge.second;
            int new_cost = current_cost + edge_cost;

            if (new_cost < cost[next_vertex]) {
                cost[next_vertex] = new_cost;
                cameFrom[next_vertex] = current_vertex;
                pq.emplace(new_cost + heuristic(next_vertex, goal_vertex), next_vertex);
            }
        }
    }

    return {{}, -1};
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
