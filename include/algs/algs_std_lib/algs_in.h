#ifndef MY_ENCAP_ALGS_IN_H
#define MY_ENCAP_ALGS_IN_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class EncapIn {
private:
    std::ifstream inf;
public:
    EncapIn();
    EncapIn(const char* file);
    ~EncapIn();

    bool isEmpty();
    std::string ReadLine();
    char ReadChar();
    std::string ReadAll();
    std::string ReadString();
    int ReadInt();
    double ReadDouble();
    float ReadFloat();
    long ReadLong();
    short ReadShort();
    char ReadByte();
    bool ReadBool();
    void ReadAllStrings(std::vector<std::string> &strings);
    void ReadAllLines(std::vector<std::string> &lines);
    void ReadAllInts(std::vector<int> &ints);
    void ReadAllLongs(std::vector<long> &longs);
    void ReadAllDoubles(std::vector<double> &doubles);
    std::string* ReadAllStrings();
    std::string* ReadAllLines();
    int* ReadAllInts();
    long* ReadAllLongs();
    double* ReadAllDoubles();
};

#endif