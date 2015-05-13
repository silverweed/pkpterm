#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <algorithm>
#include "utils.hpp"

namespace Pokepon {

std::vector<std::string> split(const std::string& str, const char sep) {
	using namespace std;
	stringstream ss(str);
	string item;
	vector<string> splitted;
	while (getline(ss, item, sep)) {
		splitted.push_back(item);
	}
	return splitted;
}

// trim from end
std::string rtrim(const std::string& ss) {
	std::string s(ss);
	s.erase(std::find_if(s.rbegin(), s.rend(), 
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

} // end namespace Pokepon
