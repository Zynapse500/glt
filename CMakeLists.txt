
cmake_minimum_required(VERSION 3.1)

project(GLT)

option(GLT_BUILD_EXAMPLES "Should examples be built?" ON)


# Create new interface library
add_library(glt INTERFACE)

# Add path to header files
target_include_directories(glt INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Build examples?
if (GLT_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
