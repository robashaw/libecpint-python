// implements interface to functionality in libecpint/ecp.hpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <libecpint/ecp.hpp>

#include "docstrings.hpp"
#include "helpers.hpp"

namespace py = pybind11;
static const char* getdoc(std::string name) { return docstrings::get("ecp", name); }

/* Expose the following structure of the GaussianECP, ECP, and ECPBasis classes:

   

 */
void init_ecp(py::module_& m) {
	using GECP = libecpint::GaussianECP;
	using ECP = libecpint::ECP;
	using ECPB = libecpint::ECPBasis;
	
	py::class_<GECP> gecp(m, "GaussianECP", getdoc("gecp_summary"));
	py::class_<ECP> ecp(m, "ECP", getdoc("ecp_summary"));
	py::class_<ECPB> ecpb(m, "ECPBasis", getdoc("ecpb_summary"));
	
	// GaussianECP
	gecp.def(py::init<int, int, double, double>(), 
			 getdoc("gecp_constructor"),
			 py::arg("n") = 0, py::arg("l") = 0,
			 py::arg("x") = 1.0, py::arg("c") = 0.0
	);
	
	gecp.def_readwrite("n", &GECP::n, getdoc("gecp_n"));
	gecp.def_readwrite("l", &GECP::l, getdoc("gecp_l")); 
	gecp.def_readwrite("x", &GECP::a, getdoc("gecp_x"));
	gecp.def_readwrite("c", &GECP::d, getdoc("gecp_c"));
	
	// ECP
	ecp.def(py::init<>(), getdoc("ecp_constructor"));
	
	ecp.def_readonly("atom_id", &ECP::atom_id, getdoc("ecp_atomid"));
	ecp.def_readonly("min_exp", &ECP::min_exp, getdoc("ecp_minexp"));
	
	ecp.def("get_center", 
		[](const ECP& self) -> std::array<double, 3> {
			return self.center_;
		},
		getdoc("ecp_getcenter")
	);
	
	ecp.def("set_center", 
		[](ECP& self, std::array<double, 3>& coords) {
			self.center_ = coords;
		},
		getdoc("ecp_setcenter")
	);
		
	ecp.def("get_n", &ECP::getN, getdoc("ecp_getn"));
	ecp.def("get_l", &ECP::getL, getdoc("ecp_getl"));
	ecp.def("no_type1", &ECP::noType1, getdoc("ecp_notype1"));
	
	ecp.def("get_gaussian", 
		[](ECP& self, int i) -> GECP& {
			return self.gaussians.at(i);
		},
		getdoc("ecp_getgaussian")
	);
		
	ecp.def("add_primitive", &ECP::addPrimitive, getdoc("ecp_addprimitive"),
			py::arg("n") = 2, py::arg("l") = 0, py::arg("x") = 0.0, 
			py::arg("c") = 1.0, py::arg("sort") = false
	);
			
	ecp.def("sort", &ECP::sort, getdoc("ecp_sort"));
	ecp.def("evaluate", &ECP::evaluate, getdoc("ecp_evaluate"));
	
	// ECPBasis
	ecpb.def(py::init<>(), getdoc("ecpb_constructor"));
	
	ecpb.def("get_n", &ECPB::getN, getdoc("ecpb_getn"));
	ecpb.def("get_max_l",  &ECPB::getMaxL, getdoc("ecpb_getmaxl"));
	ecpb.def("get_n_core", &ECPB::getECPCore, getdoc("ecpb_getncore"));
	
	ecpb.def("get_atom", 
	 	[](ECPB& self, int i) -> int {
			if (i < self.getN())
				return self.getAtom(i);
			else
				return -1; 
		},
		getdoc("ecpb_getatom")
	);
		
	ecpb.def("add_ecp", &ECPB::addECP, getdoc("ecpb_addecp"),
			py::arg("U"), py::arg("atom") = 0
	);
			
	ecpb.def("get_ecp", 
		[](ECPB& self, int i) -> ECP& { return self.getECP(i); },
		getdoc("ecpb_getecp")
	);
		
	ecpb.def("add_ecp_from_file", &ECPB::addECP_from_file, getdoc("ecpb_addfromfile"),
		py::arg("q"), py::arg("coords"), py::arg("filename")
	);
	
}