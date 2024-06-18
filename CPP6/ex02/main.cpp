#include "Checker.hpp"

int main () {

	{
		std::cout << "\n[ RANDOM GENERATE EXAMPLE ]" << std::endl;
		Base* baseClass = generate();
		identify(baseClass);
		std::cout << std::endl;
	}

	{
		// std::cout << "\n[ IDENTIFY EXAMPLE ]" << std::endl;
		// A a;
		// B b;
		// C c;

		// identify(a);
		// identify(&a);

		// identify(b);
		// identify(&b);

		// identify(c);
		// identify(&c);
	}
}