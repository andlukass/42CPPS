#include "Bureaucrat.hpp"
#include <iomanip>

int main()
{
	std::cout << "\n[ GOOD EXAMPLE ]" << std::endl;
	try {
		Bureaucrat a("ping", 1);
		std::cout << "At creation: " << a << std::endl;

		a.decrement();
		std::cout << "After decrement: " << a << std::endl;

		a.increment();
		std::cout << "After increment: " << a << std::endl;

	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}


	std::cout << "\n[ CONSTRUCTOR ERROR EXAMPLE ]" << std::endl;
	try {
		Bureaucrat a("cat", 450);
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat a("cat", 0);
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "\n[ (IN/DE)CREMENT ERROR EXAMPLE ]" << std::endl;
	try {
		Bureaucrat a("grep", 1);
		a.increment();
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat a("grep", 150);
		a.decrement();
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
