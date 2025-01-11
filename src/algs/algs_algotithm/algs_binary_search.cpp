#include "../../include/algs/algs_algorithm/algs_binary_search.h"

using std::vector;

BinarySearch::BinarySearch() {}

BinarySearch::~BinarySearch() {}

int BinarySearch::IndexOf(vector<int> &a, int key)
{
    int low = 0;
    int high = a.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key < a[mid]) 
            high = mid - 1;
        else if (key > a[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int BinarySearch::rank(int key, vector<int> &a)
{
    return IndexOf(a, key);
}