#include <iostream>
#include <memory>
#include "Client.hpp"
#include "DefaultExecutor.hpp"
#include "CmnExecutor.hpp"

int main() {
	Pokepon::Client client;
	client.attachExecutor(std::make_unique<Pokepon::DefaultExecutor>());
	client.attachExecutor(std::make_unique<Pokepon::CmnExecutor>());
	client.connect();
	while (client.connected()) {
		client.process(client.readLine());
	}
}
