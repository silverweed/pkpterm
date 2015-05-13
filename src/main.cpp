#include <iostream>
#include "Socket.hpp"

using Pokepon::Socket;

int main() {
	// Create a socket and connect it to pokepon.center:12344
	Socket s;
	while (s.connected()) {
		std::cout << "line: " << s.readLine() << std::endl;
	}
}
