#include "Character.hpp"

Character::Character() : _index(0) {
}

Character::~Character() {
}

Character::Character( std::string const & name ) : _name(name), _index(0) {
}

Character::Character( const Character &src ) {
	*this = src;
}

void Character::equip( AMateria* m ) {
	if (this->_index > 3) {
		std::cout << "dont have space to equip" << std::endl;
		return ;
	}
	this->_materias[this->_index] = m;
	this->_index++;
}

void Character::use(int idx, ICharacter& target) {
	if (!this->_index) {
		std::cout << "dont know any materias" << std::endl;
		return ;
	}
	this->_materias[idx]->use(target);
}

Character& Character::operator=( const Character &src ) {
	if (&src == this) {
		return *this;
	}
	this->_name = src._name;
	return *this;
}

std::string const &Character::getName() const {
	return this->_name;
}