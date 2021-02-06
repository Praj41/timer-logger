#pragma once

#include <iostream>
#include <chrono>
#include <utility>

class Timer {
    std::chrono::time_point< std::chrono::high_resolution_clock> StartTimePoint;
    unsigned int _step, _tag;
public:
    Timer(unsigned int tag = 0) : _step(0), _tag(tag) {
        StartTimePoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        auto EndTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

        auto duration = end - start;

        std::cout << duration << "us (" << duration * 0.001 << "ms) - END Timer-" << _tag << std::endl;
    }
    void lap() {
        auto EndTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

        auto duration = end - start;

        std::cout << duration << "us (" << duration * 0.001 << "ms) - STEP_" << ++_step << " Timer-" << _tag << std::endl;
    }
    void lap_reset() {
        auto EndTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

        auto duration = end - start;

        _step = 0;
        std::cout << duration << "us (" << duration * 0.001 << "ms) - RESET_STEP_" << _step << " Timer-" << _tag << std::endl;

        StartTimePoint = std::chrono::high_resolution_clock::now();
    }
};