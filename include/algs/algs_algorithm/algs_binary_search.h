#ifndef MY_ENCAP_ALGS_BINARYSEARCH_H
#define MY_ENCAP_ALGS_BINARYSEARCH_H

#include <vector>

class BinarySearch {
public:
    BinarySearch();
    ~BinarySearch();
    static int IndexOf(std::vector<int> &a, int key);
    static int rank(int key, std::vector<int> &a);
};

#endif