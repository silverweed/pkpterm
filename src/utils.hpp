#pragma once

/**
 * Utility functions
 */
#include <string>
#include <vector>

namespace Pokepon {

// This is probably not portable, but f*ck that
constexpr auto OS_NAME = 
#ifdef _WIN32
"Windows 32-bit"
#elif _WIN64
"Windows 64-bit"
#elif __unix || __unix__
"UNIX"
#elif __APPLE__ || __MACH__
"MacOSX"
#elif __linux__
"Linux"
#elif __FreeBSD__
"FreeBSD"
#else
"Unknown"
#endif
;


std::vector<std::string> split(const std::string& str, const char sep = ' ');
std::string rtrim(const std::string& ss);

}
