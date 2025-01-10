#include "../../include/all_base_include/all_base_include.h"

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    EncapIn In("1Kints.txt");
    int *test1;
    test1 = In.ReadAllInts();
    for (int i = 0; i < 1000; i++) {
        cout << test1[i] << std::endl;
    }

    vector<int> test2;
    In.ReadAllInts(test2);
    for (int i = 0; i < test2.size(); i++) {
        cout << test2[i] << std::endl;
    }

    return 0;
}