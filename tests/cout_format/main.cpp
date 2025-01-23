#include <iostream>
#include <cstdio>
#include <string>

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

	return 0;
}
