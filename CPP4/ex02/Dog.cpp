#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog: default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain("dog ideas...");
}

Dog::Dog(const Dog& toCopy) {
	*this = toCopy;
}

Dog& Dog::operator=(const Dog& toCopy) {
	if (this == &toCopy)
		return (*this);
	*this->_brain = *toCopy._brain;
	this->_type = toCopy._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog: destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof-woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}
