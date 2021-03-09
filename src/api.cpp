// implements interface to functionality in libecpint/api.hpp
#include <pybind11/pybind11.h>
#include <libecpint/api.hpp>
#include "docstrings.hpp"
#include "helpers.hpp"

namespace py = pybind11;
static const char* getdoc(std::string name) { return docstrings::get("ecpintegrator", name); }

/* Expose the following structure of the ECPIntegrator class:

   

 */
void init_api(py::module_& m) {
	using ECPI = libecpint::ECPIntegrator;
	
    py::class_<ECPI> c(m, "ECPIntegrator", getdoc("summary"));
	
	// constructor
	c.def(py::init<>(), getdoc("constructor"));
	
	// Member variables
	c.def_readwrite("maxLB", &ECPI::maxLB, getdoc("maxlb"));
	c.def_readwrite("deriv_order", &ECPI::deriv, getdoc("derivorder")); 
	c.def_readonly("ncart", &ECPI::ncart, getdoc("ncart")); 
	c.def_readonly("natoms", &ECPI::natoms, getdoc("natoms")); 
	c.def_readonly("min_alpha", &ECPI::min_alpha, getdoc("minalpha"));
	c.def_readwrite("ecp_is_set", &ECPI::ecp_is_set, getdoc("ecpisset"));
	c.def_readwrite("basis_is_set", &ECPI::basis_is_set, getdoc("basisisset"));
	
	// Wrappers to access other member variables
	c.def("get_integrals", 
		[](ECPI& self) -> py::array_t<double> {
			return toPyArray<double>(std::move(self.integrals.data));
		},
		getdoc("getintegrals")
	);
	
	
	// Member functions
	c.def("initialize", &ECPI::init, getdoc("initialize"));
	
}