#ifndef MY_ENCAP_ALGS_SORT_H
#define MY_ENCAP_ALGS_SORT_H

#include <vector>
#include <algorithm>
#include <random>

using std::vector;

template <typename Type>
class AlgsSort {
private:
    bool Less(Type v, Type w);
    void Exch(vector<Type> &a, int i, int j);
    void Merge(vector<Type> &a, vector<Type> &aux,
        int lo, int mid, int hi);
    void QuickSort(vector<Type> &a, int lo, int hi);
    int Partition(vector<Type> &a, int lo, int hi);
public:
    void SelectionSort(vector<Type> &a);
    void InsertionSort(vector<Type> &a);
    void ShellSort(vector<Type> &a);
    void MergeSortDown(vector<Type> &a, vector<Type> &aux,
        int lo, int hi);
    void MergeSortUp(vector<Type> &a);
    void QuickSort(vector<Type> &a);
    bool IsSorted(vector<Type> &a);
    void Show(vector<Type> &a);
};

template <typename Type>
bool AlgsSort<Type>::Less(Type v, Type w)
{
    return v < w;
}

template <typename Type>
void AlgsSort<Type>::Exch(vector<Type> &a, int i, int j)
{
    Type t = a[i];
    a[i] = a[j];
    a[j] = t;
}

template <typename Type>
void AlgsSort<Type>::Merge(vector<Type> &a, vector<Type> &aux,
        int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (Less(aux[i], aux[j]))
            a[k] = aux[i++];
        else
            a[k] = aux[j++];
    }
}

template <typename Type>
void AlgsSort<Type>::QuickSort(vector<Type> &a, int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = Partition(a, lo, hi);
    QuickSort(a, lo, j-1);
    QuickSort(a, j+1, hi);
}

template <typename Type>
int AlgsSort<Type>::Partition(vector<Type> &a, int lo, int hi)
{
    int i = lo, j = hi + 1;
    Type v = a[lo];

    while (true) {
        while (Less(a[++i], v)) {
            if (i == hi)
                break;
        }
        while (Less(v, a[--j])) {
            if (j == lo)
                break;
        }
        if (i >= j)
            break;
        Exch(a, i, j);
    }
    Exch(a, lo, j);
    return j;
}

template <typename Type>
void AlgsSort<Type>::Show(vector<Type> &a)
{
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

template <typename Type>
void AlgsSort<Type>::SelectionSort(vector<Type> &a)
{
    int N = a.size();

    for (int i = 0; i < N; i++) {
        int min = i;
        for (int j = i+1; j < N; j++) {
            if (Less(a[j], a[min])) {
                min = j;
            }
        }
        Exch(a, i, min);
    }
}

template <typename Type>
void AlgsSort<Type>::InsertionSort(vector<Type> &a)
{
    int N = a.size();
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0 && Less(a[j], a[j-1]); j--) {
            Exch(a, j, j-1);
        }
    }
}

template <typename Type>
void AlgsSort<Type>::ShellSort(vector<Type> &a)
{
    int N = a.size();
    int h = 1;
    while (h < N/3)
        h = 3*h + 1;
    while (h >= 1) {
        for (int i = h; i < N; i++) {
            for (int j = i; j >= h && Less(a[j], a[j-h]); j -= h) {
                Exch(a, j, j-h);
            }
        }
        h = h/3;
    }
}

template <typename Type>
void AlgsSort<Type>::MergeSortDown(vector<Type> &a, vector<Type> &aux,
        int lo, int hi)
{
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    MergeSort(a, aux, lo, mid);
    MergeSort(a, aux, mid+1, hi);
    Merge(a, aux, lo, mid, hi);
}

template <typename Type>
void AlgsSort<Type>::MergeSortUp(vector<Type> &a)
{
    int N = a.size();
    vector<Type> aux(N);

    for (int sz = 1; sz < N; sz = sz+sz) {
        for (int lo = 0; lo < N-sz; lo += sz+sz) {
            Merge(a, aux, 
                lo, lo+sz-1, std::min(lo+sz+sz-1, N-1));
        }
    }
}

template <typename Type>
void AlgsSort<Type>::QuickSort(vector<Type> &a)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(a.begin(), a.end(), g);
    QuickSort(a, 0, a.size() - 1);
}

template <typename Type>
bool AlgsSort<Type>::IsSorted(vector<Type> &a)
{
    for (int i = 1; i < a.size(); i++)
        if (Less(a[i], a[i-1]))
            return false;

    return true;
}

#endif