#pragma once
/**
 * The client
 */
#include <string>
#include <memory>
#include <forward_list>
#include "Socket.hpp"
#include "Executor.hpp"

namespace Pokepon {

class Executor;

using Pokepon::Socket;

class Client {
	std::unique_ptr<Socket> socket;
	//std::shared_ptr<Client> self_ptr;
	std::forward_list<std::unique_ptr<Pokepon::Executor>> executors;

public:
	Client(const std::string& ip = Socket::DEFAULT_IP, 
		const unsigned short port = Socket::DEFAULT_PORT);
	~Client();
	
	bool connect();
	void disconnect();
	void attachExecutor(Pokepon::Executor *exec);

	inline bool connected() const { return socket != nullptr && socket->connected(); }
	inline std::string readLine() const { return socket->readLine(); }
};

} // end namespace Pokepon
