#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>

using namespace std;

void bubble_sort(vector<int>& v);
void insertion_sort(vector<int>& v);
void selection_sort(vector<int>& v);
vector<int> quick_sort(vector<int>& v);
vector<int> merge_sort(vector<int>& v);
void heap_sort(vector<int>& v);
void print_vector(const vector<int> &v);

#endif
