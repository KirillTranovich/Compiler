cmake_minimum_required(VERSION 3.14)
project(CMakeFlexBison)

set(CMAKE_CXX_STANDARD 17)

find_package(BISON)
find_package(FLEX)


BISON_TARGET(parser ${CMAKE_CURRENT_SOURCE_DIR}/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(scanner ${CMAKE_CURRENT_SOURCE_DIR}/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/lexer.h)
ADD_FLEX_BISON_DEPENDENCY(scanner parser main.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(a.out
        lexer.h
        main.cpp
        main.h
        ${BISON_parser_OUTPUTS}
        ${FLEX_scanner_OUTPUTS}
)

