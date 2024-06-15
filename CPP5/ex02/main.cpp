#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

int main()
{
	{
		std::cout << "\n[ GOOD EXAMPLE ]" << std::endl;
		Bureaucrat b("Robert J.", 1);
		RobotomyRequestForm f("Robert J. Jr.");
		std::cout << "At creation: " << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
		std::cout << "----------------------------------" << std::endl;

		PresidentialPardonForm f2("Robert J. Jr.");
		std::cout << "At creation: " << f2 << std::endl;
		b.signForm(f2);
		b.executeForm(f2);

		std::cout << "----------------------------------" << std::endl;
		ShrubberyCreationForm f3("Home");
		std::cout << "At creation: " << f3 << std::endl;
		b.signForm(f3);
		b.executeForm(f3);
	}

	{
		std::cout << "\n[ ERROR EXAMPLE ]" << std::endl;
		Bureaucrat b("Robert J.", 140);
		ShrubberyCreationForm f("Robert J. Jr.");
		b.executeForm(f);
		b.signForm(f);
		b.executeForm(f);
	}

	return 0;
}
