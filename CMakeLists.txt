cmake_minimum_required(VERSION 3.15)
find_package(benchmark REQUIRED)
project(Math)

# SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb")
if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR ("${CMAKE_CXX_COMPILER_ID}"
                                                     STREQUAL "GNU"))
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -ftemplate-depth=50000 -msse4.2 -O3 -Wall"
  )
  SET(CMAKE_EXE_LINKER_FLAGS " -no-pie")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Ot /arch:AVX2")
  # using Visual Studio C++
endif()

set(CMAKE_CXX_STANDARD 17)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/test")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/benchmark")

# add_executable(Math main.cpp src/math.hpp)
add_executable(sqrt_test test/sqrt_test.cpp src/math.hpp)
add_executable(log_test test/log_test.cpp src/math.hpp)
add_executable(exp_test test/exp_test.cpp src/math.hpp)
add_executable(sin_test test/sin_test.cpp src/math.hpp)


add_executable(Sin benchmark/Sin.cpp src/math.hpp)
target_link_libraries(Sin benchmark::benchmark)

add_executable(Log benchmark/Log.cpp src/math.hpp)
target_link_libraries(Log benchmark::benchmark)

add_executable(Sqrt benchmark/Sqrt.cpp src/math.hpp)
target_link_libraries(Sqrt benchmark::benchmark)

add_executable(Exp benchmark/Exp.cpp src/math.hpp)
target_link_libraries(Exp benchmark::benchmark)

add_executable(Pow benchmark/Pow.cpp src/math.hpp)
target_link_libraries(Pow benchmark::benchmark)
