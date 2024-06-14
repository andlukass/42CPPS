#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>

int main()
{
	std::cout << "\n[ GOOD EXAMPLE ]" << std::endl;
	try {

		Bureaucrat b("Robert J.", 1);
		Form f("real estate loan", 10, 50);
		std::cout << "At creation:\n" << f << std::endl;
		b.signForm(f);
		std::cout << "After sign:\n" << f << std::endl;

	} catch (std::exception &e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}


	std::cout << "\n[ CONSTRUCTOR ERROR EXAMPLE ]" << std::endl;
	try {
		Form f("real estate loan", 1, 450);
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
	try {
		Form f("real estate loan", 1, 0);
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "\n[ SIGN/EXECUTE ERROR EXAMPLE ]" << std::endl;
	Bureaucrat b("Robert J.", 100);
	Form f("real estate loan", 99, 99);
	std::cout << "At creation:\n" << f << std::endl;
	b.signForm(f);
	std::cout << "After sign:\n" << f << std::endl;
	std::cout << "\n--------Increment bureaucrat grade--------" << std::endl;

	b.increment();
	b.signForm(f);
	std::cout << "After sign:\n" << f << std::endl;

	return 0;
}
