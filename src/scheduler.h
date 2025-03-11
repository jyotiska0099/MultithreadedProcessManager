#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "common.h"
using namespace std;

class Scheduler {
public:
    void scheduleFCFS(vector<Process> processes);
    void scheduleSJF(vector<Process> processes);
    void scheduleRoundRobin(vector<Process> processes, int timeQuantum);
};

#endif // SCHEDULER_H
