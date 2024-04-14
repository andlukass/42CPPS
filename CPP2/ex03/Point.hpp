#ifndef POINT_H
# define POINT_H

# include <iostream>
# include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point( Fixed const y, Fixed const x );
		~Point();
		Point( const Point &toCopy );
		Point& operator=( const Point &toCopy );

		Fixed getX( void ) const;
		Fixed getY( void ) const;

};

	bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
