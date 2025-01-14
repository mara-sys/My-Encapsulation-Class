#ifndef MY_ENCAP_DEBUG_H
#define MY_ENCAP_DEBUG_H

#include <iostream>
#include <cstdio>

#define DBG_VN(name)                    (#name)
#define DBG_P(variable, separate)       (cout << DBG_VN(variable) << ": " << variable << separate)
#define PRINT_FILE_FUNC_LINE            cout << "[" << __FILE__ << "<"         \
                                                << __FUNCTION__ << ":"          \
                                                << __LINE__ << ">]" << endl;

class EncapDebug {

public:

public:
    EncapDebug();
    ~EncapDebug();
};

#endif
