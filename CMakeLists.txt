cmake_minimum_required(VERSION 2.8.3)

project(lbfgs)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -fPIC")

include_directories(
    include
)

add_executable(${PROJECT_NAME} src/lbfgs_sample.cpp)
