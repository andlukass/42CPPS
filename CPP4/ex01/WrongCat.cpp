#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat: default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat: Meow" << std::endl;
}
