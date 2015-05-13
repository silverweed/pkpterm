#pragma once
/**
 * Virtual class for a Connection Executor
 */
#include <string>
#include "Client.hpp"

namespace Pokepon {

class Client;

class Executor {
	virtual void setClient(Pokepon::Client *client);
protected:
	Pokepon::Client *client;
public:
	Executor();
	virtual ~Executor();
	
	virtual unsigned short execute(const std::string& msg) = 0;
	friend class Pokepon::Client;
};

} // end namespace Pokepon
