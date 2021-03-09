#include "docstrings.hpp"

namespace docstrings {
	const char* get(std::string module, std::string name){
		auto mod = module_map.find(module);
		if (mod != module_map.end()) {
			auto str = mod->second.find(name);
			if (str != mod->second.end())
				return str->second.c_str();
		}
		std::cout << std::endl;
		return default_string.c_str();
	}
}