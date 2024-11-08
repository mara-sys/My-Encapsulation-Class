#ifndef MY_ENCAP_DEBUG_H
#define MY_ENCAP_DEBUG_H

#include <iostream>
#include <cstdio>

#define DBG_VN(name)        (#name)
#define DBG_P(variable, separate)     (cout << DBG_VN(variable) << ": " << variable << separate)

class EncapDebug {

public:
    static void FileFuncLine();

public:
    EncapDebug();
    ~EncapDebug();
};

#endif
