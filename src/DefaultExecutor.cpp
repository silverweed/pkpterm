#include <string>
#include <iostream>
#include "DefaultExecutor.hpp"

namespace Pokepon {

void DefaultExecutor::execute(const std::string& msg) {
	std::cout << msg << std::endl;
}

} // end namespace Pokepon
