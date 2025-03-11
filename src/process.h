#ifndef PROCESS_H
#define PROCESS_H

#include "common.h"
using namespace std;

class ProcessManager {
public:
    void addProcess(Process process);
    void executeProcesses();
    void stopExecution();

private:
    queue<Process> processQueue;
    mutex mtx;
    condition_variable cv;
    bool running = true;
};

#endif // PROCESS_H