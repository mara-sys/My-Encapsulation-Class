#include "../../include/debug/encap_debug.h"

using std::cout;
using std::endl;

EncapDebug::EncapDebug() {}

EncapDebug::~EncapDebug() {}

void EncapDebug::FileFuncLine()
{
    cout << "[" << __FILE__ << "<" 
        << __FUNCTION__ << ":" 
        << __LINE__ << ">]" << endl;
}