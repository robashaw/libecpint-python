cmake_minimum_required(VERSION 3.12...3.18)
project(libecpint-python)

add_subdirectory(extern/pybind11)
add_subdirectory(extern/libecpint)
pybind_11_add_module(pyecpint src/main.cpp)
target_link_libraries(pyecpint PRIVATE ecpint)

target_compile_definitions(pyecpint PRIVATE VERSION_INFO=${PYECPINT_VERSION_INFO})
