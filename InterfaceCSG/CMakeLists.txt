cmake_minimum_required(VERSION 3.0)

project(InterfaceCSG LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package( Threads REQUIRED )
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(GT ${CMAKE_CURRENT_SOURCE_DIR}/../GT)

link_directories(${GT}/lib)


file ( GLOB HEADERS *.h *.hpp)
file ( GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../vectorMatrix
	${CMAKE_CURRENT_SOURCE_DIR}/../image
	${CMAKE_CURRENT_SOURCE_DIR}/../csg
        ${CMAKE_CURRENT_SOURCE_DIR}/../particle
        ${GT}/include)


target_link_libraries(${PROJECT_NAME} 
        Qt5::Widgets 
        Qt5::OpenGL 
        debug gtestd optimized gtest
        debug gmockd optimized gmock
        ${CMAKE_THREAD_LIBS_INIT}
        ${OPENGL_LIBRARIES})
