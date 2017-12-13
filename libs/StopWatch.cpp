//
// Created by Krystian Duma on 14/11/2017.
//

#include "StopWatch.h"

void StopWatch::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

double StopWatch::stop() {
    end_time = std::chrono::high_resolution_clock::now();


    long long int duration;
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    return duration / 1000000.0;
}

StopWatch::StopWatch() {
    start();
}