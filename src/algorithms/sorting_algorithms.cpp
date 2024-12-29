#include "../../include/algorithms/sorting_algorithms.h"
#include <cstddef>
#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

using namespace std;

void heapify(vector<int>& v, int n, int i);
vector<int> merge_arr(vector<int>& left, vector<int>& right);

// Speed O(n^2)
void bubble_sort(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            }
        }
    }
}

// Speed O(n^2)
void insertion_sort(vector<int>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }

        v[j + 1] = key;
    }
}

// Speed O(n^2)
void selection_sort(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        size_t minIndex = i;

        for (size_t j = i + 1; j < v.size(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
}

// Speed O(n * log n)
vector<int> quick_sort(vector<int>& v) {
    if (v.size() < 2) {
        return v;
    } else {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, v.size() - 1);
        int randIndex = distrib(gen);

        int pivot = v[randIndex];
        vector<int> less, equal, greater;

        for (size_t i = 0; i < v.size(); i++) {
            if (v[i] < pivot) {
                less.push_back(v[i]);
            } else if (v[i] > pivot) {
                greater.push_back(v[i]);
            } else {
                equal.push_back(v[i]);
            }
        }

        vector<int> left_sorted = quick_sort(less);
        vector<int> right_sorted = quick_sort(greater);

        vector<int> result;
        result.reserve(left_sorted.size() + equal.size() + greater.size());
        result.insert(result.end(), left_sorted.begin(), left_sorted.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), right_sorted.begin(), right_sorted.end());

        return result;
    }
}

// Speed O(n * log n)
vector<int> merge_sort(vector<int> &v) {
    if (v.size() == 1) {
        return v;
    }

    size_t mid = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge_arr(left, right);
}

vector<int> merge_arr(vector<int>& left, vector<int>& right) {
    vector<int> result;
    size_t leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] <= right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }

    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    return result;
}

// Speed O(n * log n)
void heap_sort(vector<int> &v) {
    int n = v.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);

        heapify(v, i, 0);
    }
}

void heapify(vector<int>& v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest]) {
        largest = left;
    }

    if (right < n && v[right] > v[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(v[i], v[largest]);

        return heapify(v, n, largest);
    }
}

void print_vector(const vector<int>& v) {
    for (const int& value : v) {
        cout << value << " ";
    }
    cout << endl;
}
