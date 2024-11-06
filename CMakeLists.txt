cmake_minimum_required(VERSION 3.27)
project(enigma)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/model/include)
include_directories(${CMAKE_SOURCE_DIR}/development/include)

file(
    GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/model/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/development/src/*.cpp"
)

add_executable(enigma ${SRC_FILES} main.cpp)
