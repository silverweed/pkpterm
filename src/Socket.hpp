#pragma once
/**
 * Socket wrapper
 */
#include <sys/socket.h>
#include <netdb.h>
#include <string>

namespace Pokepon {

class Socket {	
	constexpr static auto BUF_SIZE = 256;
	addrinfo sock_info;
	bool _connected = false;
	std::string ip;
	unsigned short port;
	int sfd = -1;
public:
	constexpr static auto DEFAULT_IP = "pokepon.center";
	constexpr static unsigned short DEFAULT_PORT = 12344;

	Socket(const std::string& ip = DEFAULT_IP, const unsigned short port = DEFAULT_PORT);
	~Socket();
	bool sock_connect();
	void sock_close();
	inline bool connected() const { return _connected; }
	std::string readLine(); 
};

} // namespace Pokepon
