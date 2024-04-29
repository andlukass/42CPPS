#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iomanip>

void print_div(const char *message) {
	std::cout << std::endl;
	std::cout << "┌────────────────────────────────┐"<< std::endl;
	std::cout << "│" << std::setw(21) << std::setfill(' ') << message << std::setw(14) << "│" << std::endl;
	std::cout << "└────────────────────────────────┘"<< std::endl;
}

int main()
{
	/*PRINCIAPL TESTS*/
	{
		print_div("CONSTRUCTORS");

		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		print_div("DESTRUCTORS");
		delete dog;
		delete cat;
	}


	/*COPIES TESTS*/
	// {
	// 	print_div("CONSTRUCTORS");
	// 	Cat cat;
	// 	Cat cat2;

	// 	print_div("ACTIONS");
	// 	std::cout << "cat idea before copy:" << std::endl;
	// 	std::cout << cat.getBrain()->getIdea(1) << std::endl;

	// 	cat2 = cat;
	// 	std::cout << "\nafter copy:" << std::endl;
	// 	cat.getBrain()->setIdea(1,"kjdslkadnfsjdnflkdas");
	// 	std::cout << cat.getBrain()->getIdea(1) << std::endl;
	// 	std::cout << cat2.getBrain()->getIdea(1) << std::endl;

	// 	print_div("DESTRUCTORS");
	// }

	return 0;
}