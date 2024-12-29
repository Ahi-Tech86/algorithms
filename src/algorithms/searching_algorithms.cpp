#include "../../include/algorithms/searching_algorithms.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int getMinimum(int x, int y);

// Speed O(n)
int linear_search(vector<int> &v, int target) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return i;
        }
    }

    return -1;
}

// Speed O(log n)
int binary_search(vector<int> &v, int target) {
    size_t left = 0;
    size_t right = v.size() - 1;

    while (left <= right) {
        size_t mid = (left + right) / 2;

        if (v[mid] == target) {
            return mid;
        } else if (v[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

// Speed O(log[log n])
int interpolation_search(vector<int> &v, int target) {
    int mid;
    int left = 0;
    int right = v.size() - 1;

    while (v[left] < target && v[right] > target) {
        if (v[right] == v[left]) {
            break;
        }

        mid = left + ((target - v[left]) * (right - left)) / (v[right] - v[left]);

        if (v[mid] < target) {
            left = mid + 1;
        } else if (v[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    if (v[left] == target) {
        return left;
    }

    if (v[right] == target) {
        return right;
    }

    return -1;
}

// Speed O(log n)
int fibonacci_search(vector<int> &v, int target) {
    // Number (m - 2)
    int fibMm2 = 0;
    // Number (m - 1)
    int fibMm1 = 1;
    // Number m
    int fibM = fibMm1 + fibMm2;

    while (fibM < v.size()) {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = getMinimum(offset + fibMm2, v.size() - 1);

        if (v[i] < target) {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        } else if (v[i] > target) {
            fibM = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        } else {
            return i;
        }
    }

    if (fibMm1 == 1 && v[v.size() - 1] == target) {
        return v.size() - 1;
    }

    return -1;
}

// Speed O(√n)
int jump_search(vector<int> &v, int target) {
    int len = v.size();

    int step = sqrt(len);

    int prev = 0;
    while (v[min(step, len) - 1] < target) {
        prev = step;
        step += sqrt(len);

        if (prev >= len) {
            return -1;
        }
    }

    while (v[prev] < target) {
        prev++;

        if (prev == min(step, len)) {
            return -1;
        }
    }

    if (v[prev] == target) {
        return prev;
    }

    return -1;
}

int getMinimum(int x, int y) {
    if (x <= y) {
        return x;
    } else {
        return y;
    }
}
