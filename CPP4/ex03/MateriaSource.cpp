#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	int index = 0;
	while (index < 4) {
		this->_materias[index++] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	int index = 0;
	while (index < 4) {
		if (this->_materias[index])
			delete this->_materias[index];
		index++;
	}
}

MateriaSource::MateriaSource( const MateriaSource &src ) {
	*this = src;
}

MateriaSource& MateriaSource::operator=( const MateriaSource &src ) {
	if (&src == this) {
		return *this;
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
			AMateria *newM = this->_materias[index];
			return newM;
		}
		index++;
	}
	std::cout << "no materia with type:  " << type << std::endl;
	return 0;
}