#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal: default constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::~Animal() {
	std::cout << "Animal: destructor called" << std::endl;
}

Animal::Animal( const Animal &toCopy ) {
	*this = toCopy;
}

Animal& Animal::operator=( const Animal &toCopy ) {
	this->_type = toCopy._type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal class doesnt have a sound" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}
