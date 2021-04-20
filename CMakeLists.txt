cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(Graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library
add_library(${PROJECT_NAME} STATIC
        include/graph.hpp
        include/adjacency_matrix_graph.hpp src/adjacency_matrix_graph.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(Graph::Graph ALIAS ${PROJECT_NAME})

# add executables
add_executable(main main.cpp)
target_link_libraries(main PRIVATE Graph::Graph)