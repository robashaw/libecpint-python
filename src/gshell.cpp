// implements interface to functionality in libecpint/gshell.hpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <libecpint/gshell.hpp>
#include <tuple>
#include "docstrings.hpp"
#include "helpers.hpp"

namespace py = pybind11;
static const char* getdoc(std::string name) { return docstrings::get("gshell", name); }

/* Expose the following structure of the GaussianShell class:

   

 */
void init_gshell(py::module_& m) {
	using GS = libecpint::GaussianShell;
	
	py::class_<GS> c(m, "GaussianShell", getdoc("summary"));
	
	// constructors
	c.def(py::init<const std::array<double, 3>&, int>(), getdoc("constructor"),
		  py::arg("coords"), py::arg("l")=0);
	
	// member variables
	c.def_readwrite("l", &GS::l, getdoc("l"));
	c.def_readonly("atom_id", &GS::atom_id, getdoc("atomid"));
	c.def_readonly("min_exp", &GS::min_exp, getdoc("minexp"));
	
	// accessors
	c.def("get_primitive", 
		[](const GS& self, int i) -> std::tuple<double, double> {
			if (i+1 > self.nprimitive())
				return std::make_tuple(0.0, 0.0);
			else
				return std::make_tuple(self.exps[i], self.coeffs[i]);
		},
		getdoc("getprimitive")
	);
		
	c.def("set_primitive",
		[](GS& self, int i, double x, double c) {
			if (i < self.nprimitive()) {
				self.exps[i] = std::max(0.0, x);
				self.coeffs[i] = c;
			}
		},
		getdoc("setprimitive"),
		py::arg("i"), py::arg("x"), py::arg("c") = 1.0
	);
		
	c.def("get_center", 
		[](const GS& self) -> std::array<double, 3> { 
			return {self.localCenter[0], self.localCenter[1], self.localCenter[2]}; 
		},
		getdoc("getcenter")
	);
	
	c.def("set_center", 
		[](GS& self, std::array<double, 3> coords) { 
			self.localCenter[0] = coords[0];
			self.localCenter[1] = coords[1];
			self.localCenter[2] = coords[2];
		}, 
		getdoc("setcenter")
	);
	
	// member functions
	c.def("add_primitive", &GS::addPrim, getdoc("addprimitive"),
		  py::arg("x"), py::arg("c")=1.0);
	
	c.def("nprimitive", &GS::nprimitive, getdoc("nprimitive"));
	c.def("ncartesian", &GS::ncartesian, getdoc("ncartesian"));
	
	 
	
}