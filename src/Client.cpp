#include <string>
#include <memory>
#include "Client.hpp"
#if DEBUG > 0
#include <iostream>
#include <typeinfo>
#endif

namespace Pokepon {

using Pokepon::Socket;

Client::Client(const std::string& ip, const unsigned short port):
	socket(new Socket(ip, port))
{}

Client::~Client() {
	disconnect();
}

bool Client::connect() {
	return socket->sock_connect();
}

void Client::disconnect() {
	socket->sock_close();
}

void Client::attachExecutor(std::unique_ptr<Pokepon::Executor> exec) {
	exec->setClient(this);
	executors.push_front(std::move(exec));
}

/**
 * Send a message to the server
 */
void Client::msg(const std::string& _msg) const {
#if DEBUG > 0
	std::clog << "[Client] sending msg: " + _msg << std::endl;
#endif
	socket->writeLine(_msg);	
}

void Client::cmn(const std::string& _msg) const {
	msg(CMN_PREFIX + _msg);
}

void Client::cmd(const std::string& _msg) const {
	msg(CMD_PREFIX + _msg);
}

void Client::process(const std::string& _msg) {
	for (auto& exc : executors) {
#if DEBUG > 0
		std::clog << "Processing executor " << typeid(*exc).name() << std::endl;
#endif
		switch (exc->execute(_msg)) {
			case 0:
				continue;
			case 1:
				return;
			case 2:
				disconnect();
				return;
		}
	}
}

} // end namespace Pokepon
