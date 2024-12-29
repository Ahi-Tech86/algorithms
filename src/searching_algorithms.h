#ifndef SEARCHING_ALGORITHMS_H
#define SEARCHING_ALGORITHMS_H

#include <vector>

using namespace std;

int jump_search(vector<int>& v, int target);
int linear_search(vector<int>& v, int target);
int binary_search(vector<int>& v, int target);
int fibonacci_search(vector<int>& v, int target);
int interpolation_search(vector<int>& v, int target);

#endif
