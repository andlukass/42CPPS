#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource &src ) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
	*this = src;
}

MateriaSource& MateriaSource::operator=( const MateriaSource &src ) {
	if (&src == this) {
		return *this;
	}
	this->~MateriaSource();
	for (int i = 0; i < 4; i++) {
		if (src._materias[i])
			this->_materias[i] = src._materias[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	int index = 0;
	while (index < 4) {
		if (!this->_materias[index]){
			std::cout << "learned " << m->getType() << std::endl;
			this->_materias[index] = m;
			return;
		}
		index++;
	}
	std::cout << "dont have enough space" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	int index = 0;
	while (index < 4) {
		if (this->_materias[index] && this->_materias[index]->getType() == type) {
			std::cout << "creating:  " << type << std::endl;
			return this->_materias[index]->clone();
		}
		index++;
	}
	std::cout << "no materia with type:  " << type << std::endl;
	return 0;
}