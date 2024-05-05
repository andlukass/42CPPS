#include "Bureaucrat.hpp"
#include <iomanip>

int main()
{
	try {

		Bureaucrat a("ping", 1);
		std::cout << a << std::endl;
		// a.increment();
		a.decrement();
		a.decrement();
		a.decrement();
		std::cout << a << std::endl;

		std::cout << "\n_____________________\n" << std::endl;

		Bureaucrat b("ls", 150);
		std::cout << b << std::endl;
		// b.decrement();
		b.increment();
		b.increment();
		b.increment();
		std::cout << b << std::endl;

	} catch (std::exception &e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}
	
	return 0;
}
