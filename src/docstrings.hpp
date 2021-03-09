#ifndef _LIBECPINT_PYTHON_DOCSTRINGS
#define _LIBECPINT_PYTHON_DOCSTRINGS

#include <string>
#include <map>

namespace docstrings {
	static const std::string default_string = "Empty"; 
	
	// submoduless
	static const std::map<std::string, std::string> main = {
		{"mainmodule", R"pbdoc(
    	    Libecpint-python
    	    -----------------------
    	    .. currentmodule:: pyecpint
    	    .. autosummary::
    	       :toctree: _generate
    	       init
    	)pbdoc"},
			   
		{"containers", R"pbdoc()pbdoc"} 
	};
	
	static const std::map<std::string, std::string> gshell = {
		{"summary", R"pbdoc(
			GaussianShell: container for one angular momentum shell of an orbital basis set 
		)pbdoc"},
		
		{"constructor",  R"pbdoc(
			Constructs a GaussianShell.
				
			Parameters
			----------
			coords - the x,y,z position (in Bohr) of the shell
			l - the angular momentum of the shell 
		)pbdoc"},
		
		{"getprimitive",  R"pbdoc(
			Parameters
			----------
			i - the index of the primitive to return
				
			Returns
			-------
			(x,c) where x is the exponent and c the coefficient of the ith primitive
			(0,0) if i is out of range 
		)pbdoc"},
		
		{"setprimitive", R"pbdoc(
			Sets the values of the ith primitive (does nothing if i is out of range)
			
			Parameters
			----------
			i - the index of the primitive to set
			x - the exponent
			c - the ccoefficient
		)pbdoc"},
	
		{"getcenter", R"pbdoc(
			Returns
			-------
			x,y,z coordinates of the shell in Bohr (as list) 
		)pbdoc"},
		
		{"setcenter", R"pbdoc(
			Sets the coordinates of the shell.
			
			Parameters
			----------
			x,y,z coordinates of the shell in Bohr (as list) 
		)pbdoc"},
		
		{"addprimitive", R"pbdoc(
			Adds a primitive Gaussian to the shell.
			
			Parameters
			-------
			x = exponent,
			c = contraction coefficient
		)pbdoc"},
			
		{"nprimitive", R"pbdoc(
			Returns
			-------
			Number of primitive gaussians in this shell
		)pbdoc"},
		
		{"ncartesian", R"pbdoc(
			Returns
			-------
			The number of cartesian gaussian orbitals for a shell of this angular momentum
		)pbdoc"},
		
		{"l", "Angular momentum of shell"},
		{"atomid", "The internal id of the atom this shell is on"},
		{"minexp", "The minimum primitive exponent in the shell"}
	};
	
	static const std::map<std::string, std::string> ecpintegrator = {
		{"summary", R"pbdoc()pbdoc"},
		   
		{"init", R"pbdoc(
			Initialises the ECPIntegrator ready for use, after
			the gaussian and ECP bases have been set. 
			
			Parameters
			----------
			int deriv - the maximum order derivative needed, 0 (default), 1, or 2 
		)pbdoc"},
		
		{"getintegrals", R"pbdoc(
			Copyless access to the calculated ECP integrals as a numpy array.
				
			Returns
			-------
			a numpy array containing the integrals in row-major format
		)pbdoc"},
		
		{"maxlb", "The maximum angular momentum in the orbital basis"},
		{"derivorder", "The maximum order of derivative needed (0, 1, 2)"},
		{"ncart", "Number of cartesian gaussians in orbital basis"},
		{"natoms", "Number of distinct atoms, determined during initialize"},
		{"minalpha", "The minimum primitive exponent in the orbital basis"},
		{"ecpisset", "True if the ECP basis has been set"},
		{"basisisset", "True if the orbital basis has been set"}
	};
	
	const std::map<std::string, std::map<std::string, std::string>> module_map = {
		{"main", main},
		{"gshell", gshell},
		{"ecpintegrator", ecpintegrator}
	}; 
	
	const char* get(std::string, std::string);
}

#endif
