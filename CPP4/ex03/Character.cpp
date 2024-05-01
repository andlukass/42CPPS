#include "Character.hpp"

Character::Character() {

	int index = 0;
	while (index < 4) {
		this->_materias[index++] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
		this->_materias[i] = NULL;
	}
}

Character::Character( std::string const & name ) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

Character::Character( const Character &src ) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
	*this = src;
}

Character& Character::operator=( const Character &src ) {
	if (&src == this) {
		return *this;
	}
	this->~Character();
	for (int i = 0; i < 4; i++) {
		if (src._materias[i])
			this->_materias[i] = src._materias[i]->clone();
	}
	this->_name = src._name;
	return *this;
}

void Character::equip( AMateria* m ) {
	if (!m)
		return;
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
	if (!haveMateria(idx))
		return ;
	std::cout << this->_materias[idx]->getType() << " left on the floor" << std::endl;
	this->_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (!haveMateria(idx))
		return ;
	this->_materias[idx]->use(target);
}

AMateria* Character::getEquip(int idx) const {
	if (!haveMateria(idx))
		return NULL;
	return (this->_materias[idx]);
}

int Character::haveMateria(int idx) const {
	if (idx < 0 || idx > 3 || !this->_materias[idx]) {
		std::cout << "no materias in the slot" << std::endl;
		return (0);
	}
	return (1);
}

std::string const &Character::getName() const {
	return this->_name;
}