cmake_minimum_required(VERSION 3.12...3.18)
project(libecpint-python)

add_subdirectory(extern/pybind11)

add_subdirectory(extern/libecpint)
set(LIBECPINT_BUILD_TESTS OFF)
set(LIBECPINT_BUILD_DOCS OFF)

pybind11_add_module(pyecpint src/main.cpp)
target_include_directories(pyecpint PUBLIC 
			   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern/libecpint/include>)
target_link_libraries(pyecpint PRIVATE ecpint)

target_compile_definitions(pyecpint PRIVATE VERSION_INFO=${PYECPINT_VERSION_INFO})
