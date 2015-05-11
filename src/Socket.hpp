#pragma once
/**
 * Socket wrapper
 */
#include <sys/socket.h>
#include <netdb.h>
#include <string>

namespace Pokepon {

constexpr static auto DEFAULT_IP = "pokepon.center";
constexpr static unsigned short DEFAULT_PORT = 12344;

class Socket {	
	constexpr static auto BUF_SIZE = 256;
	addrinfo sock_info;
	bool _connected = false;
	int sfd = -1;
public:
	Socket(const std::string& ip = DEFAULT_IP, const unsigned short port = DEFAULT_PORT);
	~Socket();
	void sock_close();
	inline bool connected() const { return _connected; }
	std::string readLine(); 
};

} // namespace Pokepon
