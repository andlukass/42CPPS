#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iomanip>

int main()
{
	{
		std::cout << "\n[ GOOD EXAMPLE ]" << std::endl;
		Bureaucrat b("Robert J.", 1);
		Intern i;
		AForm *f;

		f = i.makeForm("robotomy request", "Robert J. Jr.");
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}

	{
		std::cout << "\n[ ERROR EXAMPLE ]" << std::endl;
		AForm *f;
		Intern i;

		f = i.makeForm("robotomdy request", "Robert J. Jr.");
	}

	return 0;
}
