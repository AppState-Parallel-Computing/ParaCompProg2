#ifndef HPC_HELPERS_H
#define HPC_HELPERS_H

#include <iostream>
#include <chrono>

#define TIMERSTART(label)                                                  \
    std::chrono::time_point<std::chrono::system_clock> a##label, b##label; \
    a##label = std::chrono::system_clock::now();

#define TIMERSTOP(label)                                                   \
    b##label = std::chrono::system_clock::now();                           \
    std::chrono::duration<double> delta##label = b##label-a##label;        \
    std::cout << "# elapsed time ("<< #label <<"): "                       \
              << delta##label.count()  << "s" << std::endl;

#define SPEEDUP(label1, label2) \
    double speedup##label1 = delta##label2.count()/delta##label1.count();  \
    std::cout << "SPEEDPUP (" << #label2 << "/" << #label1  << ") = "      \
              << speedup##label1 << std::endl; 

#endif
