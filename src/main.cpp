// Builds the libecpint-python module, pyecpint

#include <pybind11/pybind11.h>
#include "docstrings.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;
static const char* getdoc(std::string name) { return docstrings::get("main", name); }

void init_gshell(py::module_ &);
void init_ecp(py::module_ &);
void init_api(py::module_ &);

PYBIND11_MODULE(lib, m) {
	m.attr("__name__") = "pyecpint.lib";
    m.doc() = getdoc("mainmodule");
	
	py::module_ containers = m.def_submodule("containers", getdoc("containers"));
	init_gshell(containers);
	init_ecp(containers);
	
    init_api(m);	   
	
#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}