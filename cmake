cmake_minimum_required(VERSION 3.10)
project(UmbrellaOS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Process.cpp
    src/shellstartProcess.cpp
    src/filesystemService.cpp
    src/microKernel.cpp
)

# Create the executable
add_executable(UmbrellaOS ${SOURCES})
