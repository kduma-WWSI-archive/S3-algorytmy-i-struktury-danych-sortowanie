//
// Created by Krystian Duma on 14/11/2017.
//

#ifndef STOPWATCH_H
#define STOPWATCH_H

    #include <chrono>

    class StopWatch {

        std::chrono::high_resolution_clock::time_point start_time, end_time;

    public:
        void start();
        double stop();

    };

#endif //STOPWATCH_H