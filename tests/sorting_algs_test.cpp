#include "../src/sorting_algorithms.h"
#include <algorithm>
#include <stdexcept>
#include "assert.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void run_tests() {
    cout << "Running Tests..." << endl;
    vector<int> original_vector = {10, 7, 4, 1, 9, 6, 3, 8, 5, 2};
    vector<int> sorted_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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

    // Bubble sort test
    vector<int> v1 = original_vector;
    bubble_sort(v1);
    check_test(v1 == sorted_vector && is_sorted(v1.begin(), v1.end()), "Bubble sort");

    // Insertion sort test
    vector<int> v2 = original_vector;
    insertion_sort(v2);
    check_test(v2 == sorted_vector && is_sorted(v2.begin(), v2.end()), "Insertion sort");

    // Selection sort test
    vector<int> v3 = original_vector;
    selection_sort(v3);
    check_test(v3 == sorted_vector && is_sorted(v3.begin(), v3.end()), "Selection sort");

    // Quick sort test
    vector<int> v4 = original_vector;
    v4 = quick_sort(v4);
    check_test(v4 == sorted_vector && is_sorted(v4.begin(), v4.end()), "Quick sort");

    // Merge sort test
    vector<int> v5 = original_vector;
    v5 = merge_sort(v5);
    check_test(v5 == sorted_vector && is_sorted(v5.begin(), v5.end()), "Merge sort");

    // Heap sort test
    vector<int> v6 = original_vector;
    heap_sort(v6);
    check_test(v6 == sorted_vector && is_sorted(v6.begin(), v6.end()), "Heap sort");

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
