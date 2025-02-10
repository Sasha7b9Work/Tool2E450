cmake_minimum_required(VERSION 3.14)

project (Tool2E450)

set (TARGET_NAME Tool2E450)

set(CMAKE_UNITY_BUILD ON)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    add_definitions(-DDEBUG)
endif()

add_subdirectory(Panel)
