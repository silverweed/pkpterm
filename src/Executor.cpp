#include <string>
#include "Executor.hpp"

namespace Pokepon {

Executor::Executor() {}

Executor::~Executor() {}

void Executor::setClient(Pokepon::Client *cl) {
	client = cl;
}

}
