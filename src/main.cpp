// main.cpp
#include <pybind11/pybind11.h>
#include <libecpint.hpp>
#include "docstrings.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;
namespace ds = docstrings;

PYBIND11_MODULE(pyecpint, m) {
    m.doc() = ds::main_module.c_str(); 

    py::class_<libecpint::ECPIntegrator>(m, "ECPIntegrator")
		.def(py::init<>())
		.def("initialize", &libecpint::ECPIntegrator::init, ds::ecpintegrator_init.c_str())
		.def_readwrite("maxLB", &libecpint::ECPIntegrator::maxLB, ds::ecpintegrator_maxlb.c_str())
		.def_readwrite("deriv_order", &libecpint::ECPIntegrator::deriv, ds::ecpintegrator_derivorder.c_str()); 	   

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}