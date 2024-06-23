#include "Checker.hpp"

int main () {

	{
		std::cout << "\n[ RANDOM GENERATE EXAMPLE ]" << std::endl;
		Base* b = generate();

		identify(b);

		delete b;

		std::cout << std::endl;
	}

	{
		std::cout << "\n[ IDENTIFY EXAMPLE ]" << std::endl;

		A a;
		B b;
		C c;

		identify(a);
		identify(b);
		identify(c);

		std::cout << std::endl;
	}
}