cmake_minimum_required(VERSION 2.8)
project(Exercise)
enable_testing()

add_definitions(-std=c++17 -Wall -Wextra)

include_directories(./include)

set(SourceFiles
./source/calculations.cpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework chrono system REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

#Binary
add_executable(m-choose-n ./source/main.cpp ${SourceFiles})
target_link_libraries(m-choose-n ${Boost_LIBRARIES})

#Tests
add_executable(test_calculations ./test/test_calculations.cpp ${SourceFiles})
target_link_libraries(test_calculations ${Boost_LIBRARIES})
add_test(test_calculations test_calculations)

