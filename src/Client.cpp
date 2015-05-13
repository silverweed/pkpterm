#include <string>
#include <memory>
#include "Client.hpp"

namespace Pokepon {

using Pokepon::Socket;

Client::Client(const std::string& ip, const unsigned short port):
	socket(new Socket(ip, port))//,
	//self_ptr(this) // prevent executors to try destroying this client
{}

Client::~Client() {
	//self_ptr = nullptr;
}

bool Client::connect() {
	return socket->sock_connect();
}

void Client::attachExecutor(Pokepon::Executor *exec) {
	executors.push_front(std::unique_ptr<Pokepon::Executor>(exec));
	exec->setClient(std::shared_ptr<Client>(this));
}

} // end namespace Pokepon
