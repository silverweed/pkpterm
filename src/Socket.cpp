#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "Socket.hpp"

namespace Pokepon {

/**
 * Constructs the socket 
 */
Socket::Socket(const std::string& ip, const unsigned short port):
	ip(ip), port(port) 
{
	sock_info.ai_family = AF_UNSPEC;
	sock_info.ai_socktype = SOCK_STREAM;
	sock_info.ai_flags = 0;
	sock_info.ai_protocol = 0;
}

bool Socket::sock_connect() {
	addrinfo *results;
	if (getaddrinfo(ip.c_str(), std::to_string(port).c_str(), &sock_info, &results) != 0) {
		std::cerr << "[Socket] Error in getaddrinfo()." << std::endl;
		return false;
	}

	// Connect to first good socket
	for (addrinfo *it = results; it != NULL; it = it->ai_next) {
		sfd = socket(it->ai_family, it->ai_socktype, it->ai_protocol);
		if (sfd < 0)
			continue;
		if (connect(sfd, it->ai_addr, it->ai_addrlen) != -1) {
			_connected = true;
			break;
		}
		close(sfd);
	}

	freeaddrinfo(results);

	if (!_connected) {
		std::cerr << "[Socket] Error: could not connect to " << ip << ":" << port << std::endl;
		return false;
	}
	// connect successful
	return true;
}

Socket::~Socket() {
	sock_close();
}

/**
 * Reads a single line from the socket, blocking until a message is received.
 */
std::string Socket::readLine() { 
	char buf;
	std::string buffer;

	do {
		if (read(sfd, &buf, 1) < 1) {
			std::cerr << "[Socket] Read error" << std::endl;
			sock_close();
			break;
		}

		if (buf == EOF) {
			sock_close();
			break;
		}

		buffer.push_back(buf);

		if (buf == '\n') 
			break; 

	} while (true); 

	// if the line was terminated by "\r\n", ignore the
	// "\r". the "\n" is not in the buffer
	if (buffer.back() == '\r') 
		buffer.pop_back();

#if DEBUG > 0
	std::clog << "[Socket] read: " + buffer << std::endl;
#endif
	return buffer;
}

void Socket::writeLine(const std::string& msg) {
	std::string m = msg + '\n';
	send(sfd, m.c_str(), m.length(), MSG_DONTWAIT);
}

void Socket::sock_close() {
#if DEBUG > 0
	std::clog << "called sock_close()" << std::endl;
#endif
	close(sfd);
	_connected = false;
}

} // namespace Pokepon
