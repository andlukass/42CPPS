#include "Point.hpp"

Point::Point() : 
	_x(Fixed(0)), _y(Fixed(0)) {
}

Point::Point( Fixed const y, Fixed const x ) : 
	_x(Fixed(x)), _y(Fixed(y)) {
}

Point::~Point() {

}

Point::Point( const Point &toCopy ) : 
	_x(toCopy.getX()), _y(toCopy.getY()) {
}

Point& Point::operator=(const Point &toCopy) {
	(void)toCopy;
	return *this;
}

Fixed Point::getX( void ) const {
	return (this->_x);
}

Fixed Point::getY( void ) const {
	return (this->_y);
}
