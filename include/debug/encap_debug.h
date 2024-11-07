#ifndef MY_ENCAP_DEBUG_H
#define MY_ENCAP_DEBUG_H

#include <iostream>
#include <cstdio>

// #define DBG_VN(name)    (#name)

class EncapDebug {

public:
    static void FileFuncLine();
    // static void CoutVariableSpace(const char separate_char, 
    //     const char *s, ...);

public:
    EncapDebug();
    ~EncapDebug();
};

#endif
