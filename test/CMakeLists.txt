set(TARGET testToyRobot)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/external)

aux_source_directory(. DIR_SRCS)

add_executable(${TARGET} ${DIR_SRCS})

target_link_libraries(${TARGET} libTOYROBOT gtest gtest_main)
