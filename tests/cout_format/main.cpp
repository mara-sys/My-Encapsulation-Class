#include <iostream>
#include <cstdio>
#include <string>

#include "../../include/debug/encap_debug.h"

using namespace std;

int main()
{
	cout << "hello world" << endl;

    EncapDebug::FileFuncLine();

    int a = 5;
    double b = 3.1;
    char c = 'm';

    DBG_P(a, ';');
    DBG_P(b, ' ');
    DBG_P(c, endl);

	return 0;
}
