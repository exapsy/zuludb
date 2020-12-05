cmake_minimum_required(VERSION 3.19)
project(ZuluDB)

add_subdirectory(${CMAKE_SOURCE_DIR}/pkg)
add_subdirectory(${CMAKE_SOURCE_DIR}/internal)

add_executable(ZuluDB cmd/server/main.cpp)
target_link_libraries(ZuluDB InternalZuluDB)

