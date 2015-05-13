#include <string>
#include <iostream>
#include "DefaultExecutor.hpp"

namespace Pokepon {

unsigned short DefaultExecutor::execute(const std::string& msg) {
	std::cout << msg << std::endl;
	return 1;
}

} // end namespace Pokepon
