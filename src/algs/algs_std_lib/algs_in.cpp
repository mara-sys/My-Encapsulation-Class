#include "../../include/algs/algs_std_lib/algs_in.h"

using namespace std;

EncapIn::EncapIn()
{}

EncapIn::EncapIn(const char* file)
{
    if (file == nullptr) throw "file argument is null";

    inf.open(file);
    if (!inf.is_open()) throw "could not read file";
}

EncapIn::~EncapIn()
{
    inf.close();
}

bool EncapIn::isEmpty()
{
    return inf.eof();
}

string EncapIn::ReadLine()
{
    string s;
    if (inf.eof())
        return nullptr;

    getline(inf, s);
    return s;
}

char EncapIn::ReadChar()
{
    if (inf.eof())
        return '\0';
    
    return inf.get();
}

string EncapIn::ReadAll()
{
    if (inf.eof())
        return nullptr;

    streampos pos = inf.tellg();
    inf.seekg(0, std::ios::end);
    streamsize size = inf.tellg() - pos;
    // Reposition to previous position
    inf.seekg(pos);

    string s;
    inf.read(&s[0], size);

    return s;
}

string EncapIn::ReadString()
{
    string s;
    if (inf.eof())
        return nullptr;

    inf >> s;
    return s;
}

int EncapIn::ReadInt()
{
    if (inf.eof())
        throw "reach the end of the file";

    int num;
    inf >> num;
    return num;
}

double EncapIn::ReadDouble()
{
    if (inf.eof())
        throw "reach the end of the file";

    double num;
    inf >> num;
    return num;
}

float EncapIn::ReadFloat()
{
    if (inf.eof())
        throw "reach the end of the file";

    float num;
    inf >> num;
    return num;
}

long EncapIn::ReadLong()
{
    if (inf.eof())
        throw "reach the end of the file";

    long num;
    inf >> num;
    return num;
}

short EncapIn::ReadShort()
{
    if (inf.eof())
        throw "reach the end of the file";

    short num;
    inf >> num;
    return num;
}

char EncapIn::ReadByte()
{
    return ReadChar();
}

bool EncapIn::ReadBool()
{
    if (inf.eof())
        throw "reach the end of the file";

    bool value;
    inf >> value;
    return value;
}

void EncapIn::ReadAllStrings(vector<string> &strings)
{
    istringstream iss(ReadAll());
    string temp;
    while (iss >> temp) {
        strings.push_back(temp);
    }
}

void EncapIn::ReadAllLines(vector<string> &lines)
{
    while (!inf.eof()) {
        lines.push_back(ReadLine());
    }
}

void EncapIn::ReadAllInts(vector<int> &ints)
{
    while (!inf.eof()) {
        ints.push_back(ReadInt());
    }
}

void EncapIn::ReadAllLongs(vector<long> &longs)
{
    while (!inf.eof()) {
        longs.push_back(ReadLong());
    }
}

void EncapIn::ReadAllDoubles(vector<double> &doubles)
{
    while (!inf.eof()) {
        doubles.push_back(ReadDouble());
    }
}

string* EncapIn::ReadAllStrings()
{
    vector<string> s;
    ReadAllStrings(s);
    string* s_array = new string[s.size()];
    for (int i = 0; i < s.size(); i++) {
        s_array[i] = s[i];
    }

    return s_array;
}

string* EncapIn::ReadAllLines()
{
    vector<string> l;
    ReadAllLines(l);
    string* l_array = new string[l.size()];
    for (int i = 0; i < l.size(); i++) {
        l_array[i] = l[i];
    }

    return l_array;
}

int* EncapIn::ReadAllInts()
{
    vector<int> ints;
    ReadAllInts(ints);
    int *int_array = new int[ints.size()];
    for (int i = 0; i < ints.size(); i++) {
        int_array[i] = ints[i];
    }

    return int_array;
}

long* EncapIn::ReadAllLongs()
{
    vector<long> longs;
    ReadAllLongs(longs);
    long *long_array = new long[longs.size()];
    for (int i = 0; i < longs.size(); i++) {
        long_array[i] = longs[i];
    }

    return long_array;
}

double* EncapIn::ReadAllDoubles()
{
    vector<double> doubles;
    ReadAllDoubles(doubles);
    double *double_array = new double[doubles.size()];
    for (int i = 0; i < doubles.size(); i++) {
        double_array[i] = doubles[i];
    }

    return double_array;
}
