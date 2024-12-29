#include "searching_algorithms.h"
#include "sorting_algorithms.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vector = {10, 7, 4, 1, 9, 6, 3, 8, 5, 2};

    cout << "Before sorting:" << endl;
    print_vector(vector);

    heap_sort(vector);

    cout << "After sorting:" << endl;
    print_vector(vector);

    cout << fibonacci_search(vector, 9) << endl;
}
