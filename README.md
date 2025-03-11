# Description
This project aims to create a multithreaded process manager that can handle multiple processes and threads with different scheduling policies. It uses std::thread, std::mutex, and std::condition_variable for synchronization and provides a basic console-based real-time dashboard.


### Directory Overview
- **`src/`**: Contains the source code files for the process manager, including process handling, scheduling, and dashboard functionalities.
- **`include/`**: Contains common header files used across the project.
- **`build/`**: Directory where compiled files will be generated.
- **`CMakeLists.txt`**: (Optional) CMake configuration file for building the project.

### Build Instructions
To build the project using CMake:
```sh
mkdir build
cd build
cmake ..
make

