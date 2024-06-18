#include "Checker.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	srand(time(0));

	int result = rand() % 3;
	switch (result)
	{
	case 1:
		return new A;
	case 2:
		return new B;
	case 3:
		return new C;
	}
}

void identify(Base* p) {
	A* a = dynamic_cast<A*>(p);
}

void identify(Base& p) {

}