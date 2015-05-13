#include <string>
#include <vector>
#include "CmnExecutor.hpp"
#include "utils.hpp"
#if DEBUG > 0
#include <iostream>
#endif

namespace Pokepon {

unsigned short CmnExecutor::execute(const std::string& msg) {
	if (msg[0] != Pokepon::Client::CMN_PREFIX) return 0;
	
	auto tokens = Pokepon::split(rtrim(msg.substr(1)));
	auto cmn = tokens[0];

#if DEBUG > 1
	for (auto t : tokens)
		std::clog << "tokens: " << t << std::endl;
#endif
#if DEBUG > 0
	std::clog << "cmn: ^" << cmn << "$" << std::endl;
#endif

	if (cmn == "youros") {
		client->cmn(std::string("myos ") + Pokepon::OS_NAME);
	}

	return 1;
}

} // end namespace Pokepon
