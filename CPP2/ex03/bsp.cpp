#include "Point.hpp"
#include <cmath>

typedef struct s_triangle {
	Fixed a;
	Fixed b;
	Fixed c;
} t_triangle;

float ft_sqrt(float x) {
	float guess = x / 2.0f;
	for (int i = 0; i < 10; ++i) {
		guess = (guess + x / guess) / 2.0f;
	}
	return guess;
}

static Fixed getEdgeSize(Fixed diffX, Fixed diffY) {
	Fixed diff = diffX * diffX + diffY * diffY;
	Fixed size = ft_sqrt(diff.toFloat());
	return (size);
}

static t_triangle getTriangle(Point const a, Point const b, Point const c) {
	t_triangle triangle;

	triangle.a = getEdgeSize(a.getX() - b.getX(), a.getY() - b.getY());
	triangle.b = getEdgeSize(c.getX() - b.getX(), c.getY() - b.getY());
	triangle.c = getEdgeSize(a.getX() - c.getX(), a.getY() - c.getY());

	return (triangle);
}

static bool isValidTriangle(t_triangle triangle) {
	if ((triangle.a + triangle.b) <= triangle.c ||
		(triangle.a + triangle.c) <= triangle.b ||
		(triangle.c + triangle.b) <= triangle.a)
		return false;
	return true;
}

static Fixed calculateArea( Point const a, Point const b, Point const c ) {
	t_triangle triangle = getTriangle(a, b ,c);
	
	if (!isValidTriangle(triangle))
		return 0;

	Fixed semiperimeter = (triangle.a + triangle.b + triangle.c) / 2;

	Fixed result = semiperimeter * 
			(semiperimeter - triangle.a) *
			(semiperimeter - triangle.b) *
			(semiperimeter - triangle.c);
	Fixed area = ft_sqrt(result.toFloat());
	return (area);
}

static bool isEqual(Fixed a, Fixed b) {
	Fixed diff = a - b;
	if (diff < 0)
		diff = diff * -1;
	if (diff < 1)
		return true;
	return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {

	Fixed tempArea1 = calculateArea(point, a, b);
	Fixed tempArea2 = calculateArea(point, a, c);
	Fixed tempArea3 = calculateArea(point, b, c);

	Fixed pointArea = tempArea1 + tempArea2 + tempArea3;
	Fixed triangleArea = calculateArea(a, b, c);

	// std::cout << "area of point: " << pointArea << std::endl;
	// std::cout << "area of triangle: " << triangleArea << std::endl;
	if (tempArea1 == 0 || tempArea2 == 0 || tempArea3 == 0)
		return false;
	if (!isEqual(pointArea, triangleArea))
		return false;
	return true;
}