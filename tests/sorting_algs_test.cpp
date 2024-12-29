#include "../src/sorting_algorithms.h"
#include <algorithm>
#include <stdexcept>
#include "assert.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void run_tests() {
    std::cout << "Running Tests..." << std::endl;
    std::vector<int> original_vector = {10, 7, 4, 1, 9, 6, 3, 8, 5, 2};
    std::vector<int> sorted_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int passed_tests = 0;
    int failed_tests = 0;

    auto check_test = [&](bool condition, const std::string& test_name) {
        if (condition) {
            std::cout << "[PASSED] " << test_name << std::endl;
            passed_tests++;
        } else {
            std::cout << "[FAILED] " << test_name << std::endl;
            failed_tests++;
        }
    };

    // Bubble sort test
    std::vector<int> v1 = original_vector;
    bubble_sort(v1);
    check_test(v1 == sorted_vector && std::is_sorted(v1.begin(), v1.end()), "Bubble sort");

    // Insertion sort test
    std::vector<int> v2 = original_vector;
    insertion_sort(v2);
    check_test(v2 == sorted_vector && std::is_sorted(v2.begin(), v2.end()), "Insertion sort");

    // Selection sort test
    std::vector<int> v3 = original_vector;
    selection_sort(v3);
    check_test(v3 == sorted_vector && std::is_sorted(v3.begin(), v3.end()), "Selection sort");

    // Quick sort test
    std::vector<int> v4 = original_vector;
    v4 = quick_sort(v4);
    check_test(v4 == sorted_vector && std::is_sorted(v4.begin(), v4.end()), "Quick sort");

    // Merge sort test
    std::vector<int> v5 = original_vector;
    v5 = merge_sort(v5);
    check_test(v5 == sorted_vector && std::is_sorted(v5.begin(), v5.end()), "Merge sort");

    // Heap sort test
    std::vector<int> v6 = original_vector;
    heap_sort(v6);
    check_test(v6 == sorted_vector && std::is_sorted(v6.begin(), v6.end()), "Heap sort");

    std::cout << "\nSummary:" << std::endl;
    std::cout << "Passed tests: " << passed_tests << std::endl;
    std::cout << "Failed tests: " << failed_tests << std::endl;

    if (failed_tests == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed. Please check the output above." << std::endl;
    }
}

int main() {
    run_tests();
    return 0;
}
