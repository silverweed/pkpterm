#include <string>
#include <memory>
#include "Executor.hpp"

namespace Pokepon {

Executor::Executor() {}

Executor::~Executor() {
	// Release the pointer to the client, but don't destroy it
	client = nullptr;
}

void Executor::setClient(std::shared_ptr<Pokepon::Client> cl) {
	client = cl;
}

}
