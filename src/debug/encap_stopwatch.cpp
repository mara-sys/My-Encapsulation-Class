#include "../../include/debug/encap_stopwatch.h"

EncapStopWatch::EncapStopWatch()
{
#ifdef __linux__
    gettimeofday(&start, NULL);
#elif _WIN32
    start = std::chrono::high_resolution_clock::now();
#endif
}

double EncapStopWatch::ElapsedTime()
{
#ifdef __linux__
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    elapsed_time = seconds + (double)useconds/1000000;
#elif _WIN32
    end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>
        (end - start);
    elapsed_time = (double)time.count() / 1000;
#endif
    return elapsed_time;
}