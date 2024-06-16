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

bool hasNoDecimal(double value) {
	return std::fabs(value - static_cast<int>(value)) < 1e-9;
}

void print_char( double nbr ){
	std::cout << "char: ";
	if (nbr < std::numeric_limits<char>::min() ||
			nbr > std::numeric_limits<char>::max() || std::isnan(nbr)) {
		std::cout << "impossible";
	} else if (nbr < 32 || nbr > 126) {
		std::cout << "Non displayable";
	} else {
		std::cout << (char)nbr;
	}
	std::cout << std::endl;
}

void print_int( double nbr ){
	std::cout << "int: ";
	if (nbr < std::numeric_limits<int>::min() ||
			nbr > std::numeric_limits<int>::max() || std::isnan(nbr)) {
		std::cout << "impossible";
	} else {
		std::cout << (int)nbr;
	}
	std::cout << std::endl;
}

void print_float( double nbr ){
	std::cout << "float: ";
	if (nbr < std::numeric_limits<float>::min()) {
		std::cout << "-inf";
	} else if (nbr > std::numeric_limits<float>::max()) {
		std::cout << "+inf";
	} else if (std::isnan(nbr)) {
		std::cout << "nan";
	} else if (hasNoDecimal(nbr)) {
		std::cout << (float)nbr << ".0";
	} else {
		std::cout << (float)nbr;
	}
	std::cout << "f" << std::endl;

}

void print_double( double nbr ){
	std::cout << "double: ";
	if (hasNoDecimal(nbr)) {
		std::cout << nbr << ".0";
	} else {
		std::cout << nbr;
	}
	std::cout << std::endl;

}


double stringToDouble(const std::string& str) {
    double value = 0.0;
    unsigned long i = 0;
    bool is_negative = false;

    // Handle optional sign
    if (i < str.length() && (str[i] == '-' || str[i] == '+')) {
        is_negative = (str[i] == '-');
        ++i;
    }

    // Build the integer part
    while (i < str.length() && std::isdigit(str[i])) {
        value = value * 10 + (str[i] - '0');
        ++i;
    }

    // Check for decimal point and handle it
    if (i < str.length() && str[i] == '.') {
        ++i;
        double decimal_divisor = 1.0;
        while (i < str.length() && std::isdigit(str[i])) {
            decimal_divisor *= 10;
            value += (str[i] - '0') / decimal_divisor;
            ++i;
        }
    }

    // Check for any remaining characters (invalid input)
    if (i != str.length()) {
        return NAN;
    }

    return is_negative ? -value : value;
}

void ScalarConverter::convert( std::string literal ) {
	double value = stringToDouble(literal);
	std::cout << value << std::endl;
// double value = NAN;

	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
	(void)literal;
}