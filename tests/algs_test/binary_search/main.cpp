#include "../../include/all_base_include/all_base_include.h"

#include <algorithm>
#include <vector>

using std::vector;

int main(int argc, char *argv[])
{
    EncapIn in(argv[1]);
    vector<int> a;
    in.ReadAllInts(a);

    sort(a.begin(), a.end());

    int key;
    while(std::cin >> key) {
        if (BinarySearch::IndexOf(a, key) == -1)
            std::cout << "not find: " << key << std::endl;
    }
}