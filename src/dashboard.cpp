#include "dashboard.h"
using namespace std;

void Dashboard::displayProcessStatus(vector<Process> processes) {
    std::cout << "Process Status Dashboard:" << endl;
    for (const auto& process : processes) {
        std::cout << "Process ID: " << process.id << ", Burst Time: " << process.burstTime << ", Arrival Time: " << process.arrivalTime << endl;
    }
}
