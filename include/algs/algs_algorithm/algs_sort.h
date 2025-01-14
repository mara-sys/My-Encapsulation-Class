#ifndef MY_ENCAP_ALGS_SORT_H
#define MY_ENCAP_ALGS_SORT_H

#include <vector>

using std::vector;

template <typename Type>
class AlgsSort {
private:
    bool Less(Type v, Type w);
    void Exch(vector<Type> &a, int i, int j);
public:
    void SelectionSort(vector<Type> &a);
    void InsertionSort(vector<Type> &a);
    void ShellSort(vector<Type> &a);
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
bool AlgsSort<Type>::IsSorted(vector<Type> &a)
{
    for (int i = 1; i < a.size(); i++)
        if (Less(a[i], a[i-1]))
            return false;

    return true;
}

#endif