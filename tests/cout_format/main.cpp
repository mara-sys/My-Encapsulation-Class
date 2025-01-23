#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "../../include/all_base_include/all_base_include.h"

using namespace std;

int main()
{
	cout << "hello world" << endl;

    PRINT_FILE_FUNC_LINE;

    double a = 3.5;
    int b = 5;

    DBG_P(a, ' ');
    DBG_P(b, endl);

    try {
        EncapDate Date0(2, 29, 2025);
    }
    catch (const char *s) {
        cout << s << endl;
    }
    
    EncapDate Date1(2, 28, 2025);
    EncapDate Date2(1, 24, 2025);

    cout << (Date1 < Date2) << endl;

    std::vector<AlgsTransaction> trans;
    try {
    trans.push_back(AlgsTransaction("Turing   6/17/1990  644.08"));
    trans.push_back(AlgsTransaction("Tarjan   3/26/2002 4121.85"));
    trans.push_back(AlgsTransaction("Knuth    6/14/1999  288.34"));
    trans.push_back(AlgsTransaction("Dijkstra 8/22/2007 2678.40"));
    }
    catch (const char *s) {
        cout << s << endl;
    }

    cout << "Unsorted" << endl;
    for (int i = 0; i < trans.size(); i++) {
        cout << trans[i].ToString() << endl;
    }

    cout << "Sort by date\n";
    sort(trans.begin(), trans.end(), AlgsTransaction::WhenOrder);
    for (int i = 0; i < trans.size(); i++) {
        cout << trans[i].ToString() << endl;
    }

    cout << "Sort by customer\n";
    sort(trans.begin(), trans.end(), AlgsTransaction::WhoOrder);
    for (int i = 0; i < trans.size(); i++) {
        cout << trans[i].ToString() << endl;
    }

    cout << "Sort by amount\n";
    sort(trans.begin(), trans.end(), AlgsTransaction::HowMuchOrder);
    for (int i = 0; i < trans.size(); i++) {
        cout << trans[i].ToString() << endl;
    }

	return 0;
}
