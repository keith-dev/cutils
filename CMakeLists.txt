cmake_minimum_required(VERSION 3.10)
project(s22h-cutils-unicode C CXX)

set(CMAKE_C_FLAGS "-std=c11")
set(CMAKE_CXX_FLAGS "-std=c++20")
add_compile_options(-g -Wall -Wextra)

file(GLOB_RECURSE INCS false
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE SRCS false
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(lib_${PROJECT_NAME} ${SRCS})
target_sources(lib_${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)

file(GLOB_RECURSE TEST_INCS false
	${CMAKE_CURRENT_SOURCE_DIR}/test/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/*.h)
file(GLOB_RECURSE TEST_SRCS false
	${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/*.c)
add_executable(test_${PROJECT_NAME} ${TEST_SRCS})
target_sources(test_${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test/)
target_link_libraries(test_${PROJECT_NAME} PRIVATE lib_${PROJECT_NAME})
