#ifndef _LIBECPINT_PYTHON_DOCSTRINGS
#define _LIBECPINT_PYTHON_DOCSTRINGS

#include <string>

namespace docstrings {
	
	using namespace std;
	
	const string main_module = R"pbdoc(
        Libecpint-python
        -----------------------
        .. currentmodule:: pyecpint
        .. autosummary::
           :toctree: _generate
           init
    )pbdoc";
		   
	const string ecpintegrator_init = R"pbdoc(
		Initialises the ECPIntegrator ready for use, after
		the gaussian and ECP bases have been set. 
		
		Parameters
		----------
		int deriv - the maximum order derivative needed, 0 (default), 1, or 2 
	)pbdoc";
	
	const string ecpintegrator_maxlb = "The maximum angular momentum in the orbital basis";
	const string ecpintegrator_derivorder = "The maximum order of derivative needed (0, 1, 2)";
  
}

#endif
