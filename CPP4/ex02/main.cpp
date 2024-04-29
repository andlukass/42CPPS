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
	Dog dog = Dog();
	// Animal dog = Dog();
	// Animal animal = Animal();

	print_div("ACTIONS");
	std::cout << "type: " << dog.getType() << std::endl;

	print_div("DESTRUCTORS");

	return 0;
}