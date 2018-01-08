cmake_minimum_required(VERSION 3.0)

project(test_vec_mat LANGUAGES CXX)

find_package( Threads REQUIRED )

set(GT ${CMAKE_CURRENT_SOURCE_DIR}/../../GT)

link_directories(${GT}/lib)

add_executable(test_vec test_vec.cpp)

target_include_directories(test_vec PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${GT}/include)

target_link_libraries(
        test_vec
        vector_matrix
        debug gtestd optimized gtest
        debug gmockd optimized gmock
        ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_mat testMatrix.cpp)

target_include_directories(test_mat PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${GT}/include)

target_link_libraries(
        test_mat
        vector_matrix
        debug gtestd optimized gtest
        debug gmockd optimized gmock
        ${CMAKE_THREAD_LIBS_INIT})
