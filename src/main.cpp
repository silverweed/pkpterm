#include <iostream>
#include "Client.hpp"
#include "DefaultExecutor.hpp"

int main() {
	Pokepon::Client client;
	client.attachExecutor(new Pokepon::DefaultExecutor);
	client.connect();
	while (client.connected()) {
		std::cout << "line: " << client.readLine() << std::endl;
	}
}
