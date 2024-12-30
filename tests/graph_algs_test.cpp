#include "../include/algorithms/graph_algorithms.h"
#include "../include/structs/weightedGraph.h"
#include "../include/structs/graph.h"
#include <stdexcept>
#include "assert.h"
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using namespace std;

Graph init_graph() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    return g;
}

WeightedGraph init_weighted_graph() {
    WeightedGraph g(6);
    g.addEdge(0, 1, 20);
    g.addEdge(0, 2, 10);
    g.addEdge(0, 3, 40);
    g.addEdge(1, 3, 70);
    g.addEdge(1, 4, 25);
    g.addEdge(2, 3, 50);
    g.addEdge(2, 4, 100);
    g.addEdge(2, 5, 40);
    g.addEdge(3, 5, 50);
    g.addEdge(4, 5, 40);

    return g;
}

void run_tests() {
    cout << "Running Tests..." << endl;

    // For Dijkstra
    WeightedGraph graph_for_dijkstra = init_weighted_graph();
    vector<int> expected_path_for_dijkstra = {0, 2, 5};
    int expected_path_length_for_dijkstra = 50;
    int start_vertex_for_dijkstra = 0;
    int goal_vertex_for_dijkstra = 5;

    // For BFS
    Graph graph_for_bfs = init_graph();
    vector<int> expected_path_for_bfs = {0, 1, 2, 3, 4};
    int expected_path_length_for_bfs = 4;
    int start_vertex_for_bfs = 0;
    int goal_vertex_for_bfs = 4;

    // For DFS
    Graph graph_for_dfs = init_graph();
    vector<int> expected_path_for_dfs = {0, 1, 2, 3, 4};
    int expected_path_length_for_dfs = 4;
    int start_vertex_for_dfs = 0;
    int goal_vertex_for_dfs = 4;

    int passed_tests = 0;
    int failed_tests = 0;

    auto check_test = [&](bool condition, const string& test_name) {
        if (condition) {
            cout << "[PASSED] " << test_name << endl;
            passed_tests++;
        } else {
            cout << "[FAILED] " << test_name << endl;
            failed_tests++;
        }
    };

    // Dijkstra algorithm test
    auto result1 = dijkstra(graph_for_dijkstra.getAdjList(), start_vertex_for_dijkstra, goal_vertex_for_dijkstra);
    vector<int> path1 = result1.first;
    int length1 = result1.second;
    check_test(path1 == expected_path_for_dijkstra, "Dijkstra algorithm test: checking path");
    check_test(length1 == expected_path_length_for_dijkstra, "Dijkstra algorithm test: checking shortest path length");

    // BFS algorithm test
    auto result2 = bfs(graph_for_bfs.getAdjList(), start_vertex_for_bfs, goal_vertex_for_bfs);
    vector<int> path2 = result2.first;
    int length2 = result2.second;
    check_test(path2 == expected_path_for_bfs, "BFS algorithm test: checking path");
    check_test(length2 == expected_path_length_for_bfs, "BFS algorithm test: checking shortest path length");

    // DFS algorithm test
    auto result3 = bfs(graph_for_dfs.getAdjList(), start_vertex_for_dfs, goal_vertex_for_dfs);
    vector<int> path3 = result3.first;
    int length3 = result3.second;
    check_test(path3 == expected_path_for_dfs, "DFS algorithm test: checking path");
    check_test(length3 == expected_path_length_for_dfs, "DFS algorithm test: checking shortest path length");

    cout << "\nSummary:" << endl;
    cout << "Passed tests: " << passed_tests << endl;
    cout << "Failed tests: " << failed_tests << endl;

    if (failed_tests == 0) {
        cout << "All tests passed." << endl;
    } else {
        cout << "Some tests failed. Please check the output above." << endl;
    }
}

int main() {
    run_tests();
    return 0;
}
