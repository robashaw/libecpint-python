// main.cpp
#include <pybind11/pybind11.h>
#include <libecpint.hpp>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(pyecpint, m) {
    m.doc() = R"pbdoc(
        Libecpint-python
        -----------------------
        .. currentmodule:: pyecpint
        .. autosummary::
           :toctree: _generate
           init
    )pbdoc";

    py::class_<libecpint::ECPIntegrator>(m, "ECPIntegrator")
		.def(py::init<>())
		.def("initialize", &libecpint::ECPIntegrator::init)
		.def_readwrite("maxLB", &libecpint::ECPIntegrator::maxLB)
		.def_readwrite("deriv_order", &libecpint::ECPIntegrator::deriv); 	   

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}