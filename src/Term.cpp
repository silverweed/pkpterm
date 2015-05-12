#include "Term.hpp"

namespace Pokepon {

Term::Term() {
	tb_init();
}

Term::~Term() {
	tb_shutdown();
}

void Term::clear() const {
	tb_clear();
}

void Term::sync() const {
	tb_present();
}

} // end namespace Pokepon
