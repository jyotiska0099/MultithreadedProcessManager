#include "scheduler.h"
#include <algorithm>
using namespace std;

void Scheduler::scheduleFCFS(vector<Process> processes) {
    // Sort by arrival time
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    for (const auto& process : processes) {
        if (currentTime < process.arrivalTime) {
            currentTime = process.arrivalTime;
        }
        cout << "Executing Process " << process.id << " for " << process.burstTime << " seconds." << endl;
        currentTime += process.burstTime;
    }
}

void Scheduler::scheduleSJF(vector<Process> processes) {
    // Sort by burst time
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burstTime < b.burstTime;
    });

    int currentTime = 0;
    for (const auto& process : processes) {
        if (currentTime < process.arrivalTime) {
            currentTime = process.arrivalTime;
        }
        cout << "Executing Process " << process.id << " for " << process.burstTime << " seconds." << endl;
        currentTime += process.burstTime;
    }
}

void Scheduler::scheduleRoundRobin(vector<Process> processes, int timeQuantum) {
    int currentTime = 0;
    while (!processes.empty()) {
        for (auto it = processes.begin(); it != processes.end();) {
            if ((*it).burstTime <= timeQuantum) {
                cout << "Executing Process " << (*it).id << " for " << (*it).burstTime << " seconds." << endl;
                currentTime += (*it).burstTime;
                it = processes.erase(it);
            } else {
                cout << "Executing Process " << (*it).id << " for " << timeQuantum << " seconds." << endl;
                (*it).burstTime -= timeQuantum;
                currentTime += timeQuantum;
                ++it;
            }
        }
    }
}
