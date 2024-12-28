#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>

void bubble_sort(std::vector<int>& v);
void insertion_sort(std::vector<int>& v);
void selection_sort(std::vector<int>& v);
std::vector<int> quick_sort(std::vector<int>& v);
std::vector<int> merge_sort(std::vector<int>& v);
void heap_sort(std::vector<int>& v);
void print_vector(const std::vector<int> &v);

#endif
