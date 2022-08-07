cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)
set(TARGET ToyRobot)

project(${TARGET})

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(external/googletest)

aux_source_directory(. DIR_SRCS)

add_executable(${TARGET} ${DIR_SRCS})

target_link_libraries(${TARGET} libTOYROBOT)
