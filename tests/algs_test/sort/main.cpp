#include "../../include/all_base_include/all_base_include.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    EncapIn in(argv[1]);
    vector<string> a;
    in.ReadAllStrings(a);

    AlgsSort<string> sort;
    // sort.SelectionSort(a);
    // sort.InsertionSort(a);
    // sort.ShellSort(a);

    // vector<string> aux(a.size());
    // sort.MergeSortDown(a, aux, 0, a.size()-1);

    sort.MergeSortUp(a);

    cout << sort.IsSorted(a) << endl;
    sort.Show(a);
}