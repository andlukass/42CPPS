#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static void testTriangle(Point const a, Point const b, Point const c, Point const d) {
	if (bsp(a,b,c,d))
		std::cout << "INSIDE\n" << std::endl;
	else
		std::cout << "OUTSIDE\n" << std::endl;
}

int main( void ) {

	{
		std::cout << "inside test: " << std::endl;
		Point a(2,2);
		Point b(7,2);
		Point c(2,7);
		Point d(4,4);

		testTriangle(a, b, c, d);
	}

	{
		std::cout << "outside test: " << std::endl;
		Point a(2,2);
		Point b(7,2);
		Point c(2,7);
		Point d(7,7);

		testTriangle(a, b, c, d);
	}

	{
		std::cout << "in line1 test: " << std::endl;
		Point a(2,2);
		Point b(7,2);
		Point c(2,7);
		Point d(2,2);

		testTriangle(a, b, c, d);
	}

	{
		std::cout << "in line2 test: " << std::endl;
		Point a(2,2);
		Point b(7,2);
		Point c(2,7);
		Point d(4,2);

		testTriangle(a, b, c, d);
	}

	return 0;
}