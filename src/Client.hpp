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
	std::forward_list<std::unique_ptr<Pokepon::Executor>> executors;

public:
	constexpr static char CMN_PREFIX = '!';
	constexpr static char CMD_PREFIX = '/';

	Client(const std::string& ip = Socket::DEFAULT_IP, 
		const unsigned short port = Socket::DEFAULT_PORT);
	~Client();
	
	bool connect();
	void disconnect();
	void attachExecutor(std::unique_ptr<Pokepon::Executor> exec);
	void msg(const std::string& _msg) const;
	void cmd(const std::string& _msg) const;
	void cmn(const std::string& _msg) const;
	void process(const std::string& _msg);

	inline bool connected() const { return socket != nullptr && socket->connected(); }
	inline std::string readLine() const { return socket->readLine(); }
};

} // end namespace Pokepon
