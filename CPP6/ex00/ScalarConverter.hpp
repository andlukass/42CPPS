#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <iomanip>
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