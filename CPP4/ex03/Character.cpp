#include "Character.hpp"

Character::Character() {
	int index = 0;
	while (index < 4) {
		this->_materias[index++] = NULL;
	}
}

Character::~Character() {

}

Character::Character( std::string const & name ) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

Character::Character( const Character &src ) {
	*this = src;
}

Character& Character::operator=( const Character &src ) {
	if (&src == this) {
		return *this;
	}
	this->_name = src._name;
	return *this;
}

void Character::equip( AMateria* m ) {
	for (int i = 0; i < 4; i++) {
		if (!this->_materias[i]){
			this->_materias[i] = m;
			std::cout << "equiped with " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "dont have enough space" << std::endl;
}

void Character::unequip(int idx) {
	if (!this->_materias[idx]) {
		std::cout << "nothing in the slot" << std::endl;
		return ;
	}
	std::cout << "unequiped " << this->_materias[idx]->getType() << std::endl;
	this->_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (!this->_materias[idx]) {
		std::cout << "dont know any materias" << std::endl;
		return ;
	}
	this->_materias[idx]->use(target);
}

std::string const &Character::getName() const {
	return this->_name;
}