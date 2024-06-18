#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter( const ScalarConverter& toCopy ) {
	(void)toCopy;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& toCopy ) {
	(void)toCopy;
	return *this;
}

static void print_char( double nbr ){
	std::cout << "char: ";

	if (nbr < std::numeric_limits<char>::min() ||
			nbr > std::numeric_limits<char>::max() || std::isnan(nbr)) {
		std::cout << "impossible";
	} else if (nbr < 32 || nbr > 126) {
		std::cout << "Non displayable";
	} else {
		std::cout << "'" << static_cast<char>(nbr) << "'";
	}
	std::cout << std::endl;
}

static void print_int( double nbr ){
	std::cout << "int: ";
	if (nbr < std::numeric_limits<int>::min() ||
			nbr > std::numeric_limits<int>::max() || std::isnan(nbr)) {
		std::cout << "impossible";
	} else {
		std::cout << static_cast<int>(nbr);
	}
	std::cout << std::endl;
}

static void print_float( double nbr ){
	std::cout << "float: ";
	if (nbr > std::numeric_limits<float>::max()) {
		std::cout << "+";
	}
	std::cout << static_cast<float>(nbr);
	if (nbr == static_cast<int>(nbr)) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

static void print_double( double nbr ){
	std::cout << "double: ";
	if (nbr > std::numeric_limits<double>::max()) {
		std::cout << "+";
	}
	std::cout << nbr;
	if (nbr == static_cast<int>(nbr)) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

static double stringToDouble(const std::string& str) {
	char *endptr;
	double value = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0') {
		return NAN;
	}
	return value;
}

void ScalarConverter::convert( std::string literal ) {
	double value;

	value = static_cast<double>(literal[0]);
	if (literal.size() != 1) {
		value = stringToDouble(literal);
	}
	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}