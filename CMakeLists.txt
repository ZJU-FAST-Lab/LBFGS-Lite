cmake_minimum_required(VERSION 3.11)

project(lbfgs VERSION 2.3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)          # ensure cmake instructs compiler to use C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # ensure the C++ standard given before is actually used
set(CMAKE_CXX_EXTENSIONS OFF)       # avoid compile flags of the type -std=gnu++1z added by cmake

include(GNUInstallDirs)

find_package(Eigen3 REQUIRED)

option(LBFGS_BUILD_EXAMPLE "Build this library with example." ON)

add_subdirectory(include)
if(LBFGS_BUILD_EXAMPLE)
    add_subdirectory(src)
endif()