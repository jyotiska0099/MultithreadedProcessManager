#include "process.h"
using namespace std;

void ProcessManager::addProcess(Process process) {
    lock_guard<mutex> lock(mtx);
    processQueue.push(process);
    cv.notify_one();
}

void ProcessManager::executeProcesses() {
    while (running) {
        Process process;
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return !processQueue.empty() || !running; });
            if (!running && processQueue.empty()) break;
            process = processQueue.front();
            processQueue.pop();
        }
        // Execute the process
        cout << "Executing Process " << process.id << std::endl;
        // Simulate execution time
        this_thread::sleep_for(std::chrono::seconds(process.burstTime));
    }
}

void ProcessManager::stopExecution() {
    {
        lock_guard<mutex> lock(mtx);
        running = false;
    }
    cv.notify_one();
}
