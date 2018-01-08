cmake_minimum_required(VERSION 3.0)

project(test_csg_boundingBox LANGUAGES CXX)

find_package( Threads REQUIRED )

set(GT ${CMAKE_CURRENT_SOURCE_DIR}/../../GT)

link_directories(${GT}/lib)

add_executable(test_boundingBox test_boundingBox.cpp )

target_include_directories(test_boundingBox PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../../vectorMatrix
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${GT}/include)

target_link_libraries(
        test_boundingBox
        vector_matrix
        csg
        debug gtestd optimized gtest
        debug gmockd optimized gmock
        ${CMAKE_THREAD_LIBS_INIT})

