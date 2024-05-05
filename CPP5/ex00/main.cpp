#include "Bureaucrat.hpp"
#include <iomanip>

int main()
{
	try {
		Bureaucrat b("bender", 0);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
