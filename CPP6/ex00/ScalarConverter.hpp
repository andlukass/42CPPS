#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter( const ScalarConverter& toCopy);
		ScalarConverter& operator=( const ScalarConverter& toCopy);

	public:
		static void convert(std::string literal);
};