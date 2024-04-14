#include "Fixed.hpp"

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed( const int number ) {
	// std::cout << "Int constructor called" << std::endl;
	this->_raw = number * (1 << this->_bits);
}

Fixed::Fixed( const float number ) {
	// std::cout << "Float constructor called" << std::endl;
	this->_raw = number * (1 << this->_bits);
}

int Fixed::toInt ( void ) const {
	return this->_raw >> this->_bits;
}

float Fixed::toFloat( void ) const {
	float floatRaw = this->_raw * 1.0f;
	return floatRaw / (1 << this->_bits);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &toCopy ) {
	// std::cout << "Copy constructor called" << std::endl;
	this->_raw = toCopy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &toCopy) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = toCopy.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void Fixed::setRawBits( int const raw ) {
	this->_raw = raw;
}

std::ostream & operator << ( std::ostream &out, Fixed const &number ) {
	out << number.toFloat();
	return out;
}

Fixed Fixed::operator*( Fixed const &number ) {
	Fixed o(this->toFloat() * number.toFloat());
	return o;
}

Fixed Fixed::operator/( Fixed const &number ) {
	Fixed o(this->toFloat() / number.toFloat());
	return o;
}

Fixed Fixed::operator+( Fixed const &number ) {
	Fixed o(this->toFloat() + number.toFloat());
	return o;
}

Fixed Fixed::operator-( Fixed const &number ) {
	Fixed o(this->toFloat() - number.toFloat());
	return o;
}

Fixed& Fixed::operator++( void ) {
	this->_raw++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed& Fixed::operator--( void ) {
	this->_raw--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed temp(*this);
	operator--();
	return temp;
}

bool Fixed::operator==( Fixed const &number ) {
	return (this->toFloat() == number.toFloat());
}

bool Fixed::operator!=( Fixed const &number ) {
	return (this->toFloat() != number.toFloat());
}

bool Fixed::operator<=( Fixed const &number ) {
	return (this->toFloat() <= number.toFloat());
}

bool Fixed::operator>=( Fixed const &number ) {
	return (this->toFloat() >= number.toFloat());
}

bool Fixed::operator<( Fixed const &number ) {
	return (this->toFloat() < number.toFloat());
}

bool Fixed::operator>( Fixed const &number ) {
	return (this->toFloat() > number.toFloat());
}

const Fixed& Fixed::min(Fixed const &number1, Fixed const &number2) {
	if (number1.toFloat() < number2.toFloat())
		return number1;
	return number2;
}

Fixed& Fixed::min(Fixed &number1, Fixed &number2) {
	if (number1.toFloat() < number2.toFloat())
		return number1;
	return number2;
}

const Fixed& Fixed::max(Fixed const &number1, Fixed const &number2) {
	if (number1.toFloat() > number2.toFloat())
		return number1;
	return number2;
}

Fixed& Fixed::max(Fixed &number1, Fixed &number2) {
	if (number1.toFloat() > number2.toFloat())
		return number1;
	return number2;
}

