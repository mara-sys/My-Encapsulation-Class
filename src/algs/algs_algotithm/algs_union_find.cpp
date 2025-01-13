#include "../../include/algs/algs_algorithm/algs_union_find.h"

UF::UF(int N)
{
    id = new int[N];
    sz = new int[N];
    count = N;
    contact_num = N;

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

UF::~UF()
{
    delete []id;
    delete []sz;
}

int UF::Count()
{
    return count;
}

bool UF::ConnectedQF(int p, int q)
{
    return FindQF(p) == FindQF(q);
}

bool UF::ConnectedQU(int p, int q)
{
    return FindQU(p) == FindQU(q);
}

int UF::FindQF(int p)
{
    return id[p];
}

int UF::FindQU(int p)
{
    while (id[p] != p)
        p = id[p];
    
    return p;
}

void UF::QuickFind(int p, int q)
{
    int pID = FindQF(p);
    int qID = FindQF(q);

    for (int i = 0; i < contact_num; i++) {
        if (id[i] == pID)
            id[i] = qID;
    }

    count--;
}

void UF::QuickUnion(int p, int q)
{
    int pRoot = FindQU(p);
    int qRoot = FindQU(q);

    if (pRoot == qRoot)
        return;
    
    id[pRoot] = qRoot;

    count--;
}

void UF::WeightingQuickUnion(int p, int q)
{
    int pRoot = FindQU(p);
    int qRoot = FindQU(q);

    if (pRoot == qRoot)
        return;

    if (sz[pRoot] < sz[qRoot]) {
        id[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
    } else {
        id[qRoot] = pRoot;
        sz[pRoot] += sz[qRoot];
    }

    count--;
}