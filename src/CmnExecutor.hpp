#pragma once
/**
 * Communications executor
 */
#include <string>
#include "Executor.hpp"

namespace Pokepon {

class CmnExecutor : public Executor {
public:
	virtual unsigned short execute(const std::string& msg) override;
};

} // end namespace Pokepon
