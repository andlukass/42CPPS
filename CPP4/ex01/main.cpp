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
	print_div("CONSTRUCTORS");

	const Cat* cat = new Cat();
	const Animal* dog = new Dog();

	print_div("ACTIONS");

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;

	cat->getBrain()->getIdea(0);
	dog->makeSound();

	print_div("DESTRUCTORS");
	delete cat;
	delete dog;

	return 0;
}