#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>

// Define process structure
struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    int priority;
};

#endif // COMMON_H
