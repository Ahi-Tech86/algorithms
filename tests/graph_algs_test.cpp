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

void check_test(bool condition, const string& test_name, int& passed_tests, int& failed_tests) {
    if (condition) {
        cout << "[PASSED] " << test_name << endl;
        passed_tests++;
    } else {
        cout << "[FAILED] " << test_name << endl;
        failed_tests++;
    }
}

void dijkstra_test(int& passed_tests, int& failed_tests) {
    WeightedGraph graph = init_weighted_graph();
    vector<int> expected_path = {0, 2, 5};
    int expected_path_length = 50;
    int start_vertex = 0;
    int goal_vertex = 5;

    auto result = dijkstra(graph.getAdjList(), start_vertex, goal_vertex);
    vector<int> path = result.first;
    int path_length = result.second;
    check_test(path == expected_path, "Dijkstra algorithm test: checking path", passed_tests, failed_tests);
    check_test(path_length == expected_path_length, "Dijkstra algorithm test: checking shortest path length", passed_tests, failed_tests);
}

void bfs_test(int& passed_tests, int& failed_tests) {
    Graph graph = init_graph();
    vector<int> expected_path = {0, 1, 2, 3, 4};
    int expected_path_length = 4;
    int start_vertex = 0;
    int goal_vertex = 4;

    auto result = bfs(graph.getAdjList(), start_vertex, goal_vertex);
    vector<int> path = result.first;
    int path_length = result.second;
    check_test(path == expected_path, "BFS algorithm test: checking path", passed_tests, failed_tests);
    check_test(path_length == expected_path_length, "BFS algorithm test: checking shortest path length", passed_tests, failed_tests);
}

void dfs_test(int& passed_tests, int& failed_tests) {
    Graph graph = init_graph();
    vector<int> expected_path = {0, 1, 2, 3, 4};
    int expected_path_length = 4;
    int start_vertex = 0;
    int goal_vertex = 4;

    auto result = dfs(graph.getAdjList(), start_vertex, goal_vertex);
    vector<int> path = result.first;
    int path_length = result.second;
    check_test(path == expected_path, "DFS algorithm test: checking path", passed_tests, failed_tests);
    check_test(path_length == expected_path_length, "DFS algorithm test: checking shortest path length", passed_tests, failed_tests);
}

void run_tests() {
    cout << "Running Tests..." << endl;

    int passed_tests = 0;
    int failed_tests = 0;

    bfs_test(passed_tests, failed_tests);
    dfs_test(passed_tests, failed_tests);
    dijkstra_test(passed_tests, failed_tests);

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
