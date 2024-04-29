#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain("cat ideas...");
}

Cat::Cat(const Cat& toCopy) {
	this->_brain = new Brain();
	*this = toCopy;
}

Cat& Cat::operator=(const Cat& toCopy) {
	if (this == &toCopy)
		return (*this);
	*this->_brain = *toCopy._brain;
	this->_type = toCopy._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat: destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Cat: Meow" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}
