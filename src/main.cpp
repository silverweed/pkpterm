#include <iostream>
#include "Socket.hpp"

using Pokepon::Socket;

int main() {
	Socket s;
	while (s.connected()) {
		std::cout << "line: " << s.readLine() << std::endl;
	}
}
