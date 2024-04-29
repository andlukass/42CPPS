#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::~AMateria() {
}

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria( const AMateria &src ) {
	*this = src;
}

AMateria& AMateria::operator=( const AMateria &src ) {
	if (&src == this) {
		return *this;
	}
	this->_type = src._type;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "not a valid materia" << std::endl;
}
