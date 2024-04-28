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

	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal* animal = new Animal();

	const WrongAnimal* wrongCat = new WrongCat();

	print_div("ACTIONS");

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << animal->getType() << std::endl;

	std::cout << wrongCat->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	wrongCat->makeSound();

	print_div("DESTRUCTORS");
	delete cat;
	delete dog;
	delete animal;
	delete wrongCat;

	return 0;
}