#include "process.h"
#include "scheduler.h"
#include "dashboard.h"
using namespace std;

int main() {
    ProcessManager pm;
    Scheduler scheduler;
    Dashboard dashboard;

    // Create processes
    vector<Process> processes = {
        {1, 5, 0, 1},
        {2, 3, 1, 2},
        {3, 1, 2, 3},
        {4, 2, 3, 4},
        {5, 4, 4, 5}
    };

    // Display dashboard
    dashboard.displayProcessStatus(processes);

    // Schedule processes using Round Robin
    scheduler.scheduleRoundRobin(processes, 2);

    // Start process execution in a separate thread
    thread executionThread([&pm, &processes] {
        for (const auto& process : processes) {
            pm.addProcess(process);
        }
        pm.executeProcesses();
    });

    // Wait for 10 seconds before stopping execution
    this_thread::sleep_for(chrono::seconds(10));
    pm.stopExecution();

    executionThread.join();

    return 0;
}
