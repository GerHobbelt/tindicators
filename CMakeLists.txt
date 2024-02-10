cmake_minimum_required(VERSION 3.10)
project(libindicators)

# Set the C standard and optimization/debug flags
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wshadow -Wconversion -pedantic -O2 -g")

## Include directories
#include_directories(${CMAKE_SOURCE_DIR})
#include_directories(${CMAKE_SOURCE_DIR}/indicators)
#include_directories(${CMAKE_SOURCE_DIR}/utils)

# File globbing for sources
file(GLOB_RECURSE INDICATORS_SOURCES "indicators/*.c" "candles.c"
        #"beta/*.c"
)
file(GLOB_RECURSE UTILS_SOURCES "utils/*.c")

# Target for static library: libindicators.a
add_library(tulipindicators STATIC "indicators.c" ${INDICATORS_SOURCES} ${UTILS_SOURCES})
target_include_directories(tulipindicators PUBLIC ${CMAKE_CURRENT_LIST_DIR}/indicators ${CMAKE_CURRENT_LIST_DIR}/utils  ${CMAKE_CURRENT_LIST_DIR})

# Executable targets
add_executable(sample sample.c)
target_link_libraries(sample tulipindicators m)

add_executable(example1 example1.c)
target_link_libraries(example1 tulipindicators m)

add_executable(example2 example2.c)
target_link_libraries(example2 tulipindicators m)

add_executable(fuzzer fuzzer.c)
target_link_libraries(fuzzer tulipindicators m)

add_executable(smoke smoke.c)
target_link_libraries(smoke tulipindicators m)

add_executable(tulipbenchmark benchmark.c)
target_link_libraries(tulipbenchmark tulipindicators m)

add_executable(cli cli.c)
target_link_libraries(cli tulipindicators m)