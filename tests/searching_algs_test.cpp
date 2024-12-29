#include "../src/searching_algorithms.h"
#include <stdexcept>
#include "assert.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void run_tests() {
    cout << "Running Tests..." << endl;
    vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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
