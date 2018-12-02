cmake_minimum_required(VERSION 3.12)
project(riscv-simulator)

set(CMAKE_CXX_STANDARD 11)

#include pthreads
find_package(Threads)

# include the google test
include(GoogleTest)
find_package(GTest REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/test")

# create the main app
set(SOURCE_FILES cpu/alu.cpp cpu/alu.h cpu/reg.cpp cpu/reg.h cpu/cpu.cpp cpu/cpu.h mem/mem.cpp mem/mem.h translator/translator.h translator/translator.cpp)
add_executable(risc-simulator main.cpp ${SOURCE_FILES})

# create the translator app
add_executable(risc-translator translator/trans_main.cpp translator/translator.h translator/translator.cpp)

# create the alu test
add_executable(TestAll test/test-alu.cpp ${SOURCE_FILES} test/test-cpu.cpp)
target_link_libraries(TestAll gtest_main gtest ${CMAKE_THREAD_LIBS_INIT})
gtest_add_tests(TARGET TestAll)