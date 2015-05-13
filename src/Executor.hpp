#pragma once
/**
 * Virtual class for a Connection Executor
 */
#include <string>
#include <memory>
#include "Client.hpp"

namespace Pokepon {

class Client;

class Executor {
	virtual void setClient(std::shared_ptr<Pokepon::Client> client);
protected:
	std::shared_ptr<Pokepon::Client> client;
public:
	Executor();
	virtual ~Executor();
	
	virtual void execute(const std::string& msg) = 0;
	friend class Pokepon::Client;
};

} // end namespace Pokepon
