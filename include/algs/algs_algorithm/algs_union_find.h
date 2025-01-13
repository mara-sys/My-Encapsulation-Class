#ifndef MY_ENCAP_ALGS_UNIONFIND_H
#define MY_ENCAP_ALGS_UNIONFIND_H

class UF {
private:
    int *id;
    int *sz;
    int count;
    int contact_num;
public:
    UF(int N);
    ~UF();
    int Count();
    bool ConnectedQF(int p, int q);
    bool ConnectedQU(int p, int q);
    int FindQF(int p);
    int FindQU(int p);
    void QuickFind(int p, int q);
    void QuickUnion(int p, int q);
    void WeightingQuickUnion(int p, int q);
};

#endif