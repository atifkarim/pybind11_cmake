cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# project name
project(pybind11_cmake)

set(MAIN_TARGET_NAME ${PROJECT_NAME})

# C++ shared library
add_library(${MAIN_TARGET_NAME}_lib SHARED ${${PROJECT_NAME}_SOURCE_DIR}/src/base.cpp
                                           ${${PROJECT_NAME}_SOURCE_DIR}/src/child.cpp
                                           ${${PROJECT_NAME}_SOURCE_DIR}/src/test.cpp
                                           )

# Targetted directory for the target ${MAIN_TARGET_NAME}_lib
target_include_directories(${MAIN_TARGET_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Target for the executable
add_executable(${MAIN_TARGET_NAME}_exec ${PROJECT_SOURCE_DIR}/example/c++/main.cpp)

# Set the name of the executable file and the output directory
set_target_properties(${MAIN_TARGET_NAME}_exec PROPERTIES OUTPUT_NAME "pybind_cpp_exec")
set_target_properties(${MAIN_TARGET_NAME}_exec PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set_target_properties(${MAIN_TARGET_NAME}_exec PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)

# Set the name of the C++ shared library and the output directory
set_target_properties(${MAIN_TARGET_NAME}_lib PROPERTIES OUTPUT_NAME "pybind_cpp_lib")
set_target_properties(${MAIN_TARGET_NAME}_lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)
set_target_properties(${MAIN_TARGET_NAME}_lib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)

# Link the executable target to library
target_link_libraries(${MAIN_TARGET_NAME}_exec ${MAIN_TARGET_NAME}_lib)


# Adding pybind11 which is stored in the forked repository
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../forked_repo/pybind11 ${CMAKE_CURRENT_BINARY_DIR}/forked_repo/pybind11)

# Pybind target name. This is also written/used in src/py_binded.cpp file. Same name should be kept
set(PYBIND_TARGET_NAME pybind_cpp_module)

# Source file to bind pybind11
pybind11_add_module(${PYBIND_TARGET_NAME} ${PROJECT_SOURCE_DIR}/src/base.cpp
                                          ${PROJECT_SOURCE_DIR}/src/child.cpp
                                          ${${PROJECT_NAME}_SOURCE_DIR}/src/test.cpp
                                          ${PROJECT_SOURCE_DIR}/src/pybinded_file/bind_test.cpp
                                          ${PROJECT_SOURCE_DIR}/src/pybinded_file/py_binded.cpp
                                          )

# Target directory for pybinded module
target_include_directories(${PYBIND_TARGET_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Shared pybinded library's storing location is setup
set_target_properties(${PYBIND_TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)
set_target_properties(${PYBIND_TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)
