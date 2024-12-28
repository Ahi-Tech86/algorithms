#include "searching_algorithms.h"
#include "sorting_algorithms.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vector = {10, 7, 4, 1, 9, 6, 3, 8, 5, 2};

    std::cout << "Before sorting:" << std::endl;
    print_vector(vector);

    heap_sort(vector);

    std::cout << "After sorting:" << std::endl;
    print_vector(vector);

    std::cout << fibonacci_search(vector, 9) << std::endl;
}
