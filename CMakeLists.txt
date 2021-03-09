cmake_minimum_required(VERSION 3.12...3.18)
project(libecpint-python)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_subdirectory(extern/pybind11)
add_subdirectory(extern/libecpint)

include(src/Files.cmake)
pybind11_add_module(pyecpint ${PYECPINT_CPPS} ${PYECPINT_HPPS})
set_property(TARGET ecpint pyecpint PROPERTY CXX_STANDARD 14)

target_include_directories(pyecpint PUBLIC 
			   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern/libecpint/include>)
target_link_libraries(pyecpint PRIVATE ecpint)

target_compile_definitions(pyecpint PRIVATE VERSION_INFO=${PYECPINT_VERSION_INFO})
