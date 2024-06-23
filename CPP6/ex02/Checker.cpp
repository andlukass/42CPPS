#include "Checker.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	srand(time(0));

	int result = rand() % 3;
	switch (result)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	}
	return NULL;
}

void identify(Base* p) {
	std::cout << "aqui" << std::endl;
	if (!p) {
		std::cout << MESSAGE + "unknown." << std::endl;
		return ;
	}
	Base* a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << MESSAGE + "A." << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << MESSAGE + "B." << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << MESSAGE + "C." << std::endl;
		return ;
	}
}

void identify(Base& p) {
	std::string str = "The type of the class is: ";

	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << MESSAGE + "A." << std::endl;
	}
	catch(std::exception &e) { }

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << MESSAGE + "B." << std::endl;
	}
	catch(std::exception &e) { }

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << MESSAGE + "C." << std::endl;
	}
	catch(std::exception &e) { }

}