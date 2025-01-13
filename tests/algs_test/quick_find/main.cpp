#include "../../include/all_base_include/all_base_include.h"

int main(int argc, char *argv[])
{
    EncapIn in(argv[1]);
    int N = in.ReadInt();
    UF uf(N);
    
    while (!in.isEmpty()) {
        int p = in.ReadInt();
        int q = in.ReadInt();
        // if (uf.ConnectedQF(p, q))
        //     continue;
        // uf.QuickFind(p, q);

        // if (uf.ConnectedQU(p, q))
        //     continue;
        // uf.QuickUnion(p, q);

        if (uf.ConnectedQU(p, q))
            continue;
        uf.WeightingQuickUnion(p, q);
        
        std::cout << p << " " << q << std::endl;
    }
    std::cout << uf.Count() << " componnents" << std::endl;

    return 0;
}