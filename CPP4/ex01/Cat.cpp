#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain("cat ideas...");
}

Cat::~Cat() {
	std::cout << "Cat: destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat: Meow" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}
