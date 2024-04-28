#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog: default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog: destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof-woof" << std::endl;
}
