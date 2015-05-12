#pragma once
/**
 * Termbox wrapper
 */
#include <termbox.h>

namespace Pokepon {

class Term {
public:
	Term();
	~Term();

	void clear() const;
	void sync() const;
};

} // end namespace Pokepon
