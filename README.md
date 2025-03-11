# MultithreadedProcessManager
This project aims to create a multithreaded process manager that can handle multiple processes and threads with different scheduling policies. It uses std::thread, std::mutex, and std::condition_variable for synchronization and provides a basic console-based real-time dashboard.

# Project Directory Structure:

MultithreadedProcessManager/
├── src/
│   ├── Process.h
│   ├── Process.cpp
│   ├── Scheduler.h
│   ├── Scheduler.cpp
│   ├── Dashboard.h
│   ├── Dashboard.cpp
│   └── main.cpp
├── include/
│   └── common.h
├── build/
│   └── (compiled files)
└── CMakeLists.txt (optional for building)
