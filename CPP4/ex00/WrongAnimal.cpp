#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal: default constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &toCopy ) {
	*this = toCopy;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &toCopy ) {
	this->_type = toCopy._type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal class doesnt have a sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}
