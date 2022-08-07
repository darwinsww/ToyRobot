set(TARGET libTOYROBOT)

include_directories($ENV{BOOST_ROOT})
include_directories($ENV{BOOST_INCLUDEDIR})

aux_source_directory(. DIR_SRCS)

add_library(${TARGET} ${DIR_SRCS})
