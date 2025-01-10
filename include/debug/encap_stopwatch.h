#ifndef MY_ENCAP_STOPWATCH_H
#define MY_ENCAP_STOPWATCH_H

#include <iostream>
#include <chrono>
#include <sys/time.h>

class EncapStopWatch {
private:
#ifdef __linux__
    struct timeval start, end;
#elif _WIN32
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::milliseconds time;
#endif
    long seconds, useconds;
    double elapsed_time;
public:
    EncapStopWatch();
    ~EncapStopWatch() {};
    double ElapsedTime();
};

#endif