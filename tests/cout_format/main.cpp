#include <iostream>
#include <cstdio>
#include <string>

#include "../../include/all_base_include/all_base_include.h"

using namespace std;

int main()
{
	cout << "hello world" << endl;

    EncapDebug::PrintFileFuncLine();

    double a = 3.5;
    int b = 5;

    DBG_P(a, ' ');
    DBG_P(b, endl);    

	return 0;
}
