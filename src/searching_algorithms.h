#ifndef SEARCHING_ALGORITHMS_H
#define SEARCHING_ALGORITHMS_H

#include <vector>

int jump_search(std::vector<int>& v, int target);
int linear_search(std::vector<int>& v, int target);
int binary_search(std::vector<int>& v, int target);
int fibonacci_search(std::vector<int>& v, int target);
int interpolation_search(std::vector<int>& v, int target);

#endif
