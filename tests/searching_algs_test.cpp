#include "../src/searching_algorithms.h"
#include <stdexcept>
#include "assert.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void run_tests() {
    std::cout << "Running Tests..." << std::endl;
    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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

    // Test linear search
    check_test(linear_search(vector, 9) == 8, "Linear Search: Find 9");
    check_test(linear_search(vector, 11) == -1, "Linear Search: Find 11");

    // Test binary search
    check_test(binary_search(vector, 1) == 0, "Binary Search: Find 1");
    check_test(binary_search(vector, 11) == -1, "Binary Search: Find 11");

    // Test interpolation search
    check_test(interpolation_search(vector, 1) == 0, "Interpolation Search: Find 1");
    check_test(interpolation_search(vector, 12) == -1, "Interpolation Search: Find 12");

    // Test fibonacci search
    check_test(fibonacci_search(vector, 2) == 1, "Fibonacci Search: Find 2");
    check_test(fibonacci_search(vector, 13) == -1, "Fibonacci Search: Find 13");

    // Test jump search
    check_test(jump_search(vector, 3) == 2, "Jump Search: Find 3");
    check_test(jump_search(vector, 15) == -1, "Jump Search: Find 15");

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
