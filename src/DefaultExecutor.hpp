#pragma once
/**
 * Default connection executor, which reads messages and echoes them
 */
#include <string>
#include "Client.hpp"
#include "Executor.hpp"

namespace Pokepon {

class DefaultExecutor : public Executor {
public:
	virtual unsigned short execute(const std::string& msg) override;
};

} // end namespace Pokepon
