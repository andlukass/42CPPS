#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->decimal = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	this->decimal = 0;
}

Fixed::Fixed( const Fixed &toCopy ) {
	std::cout << "Copy constructor called" << std::endl;
	this->decimal = toCopy.decimal;

}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->decimal = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->decimal;
}

void Fixed::setRawBits( int const raw ) {
	this->decimal = raw;
}