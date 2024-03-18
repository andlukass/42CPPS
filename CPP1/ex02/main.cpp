#include <iostream>
#include <string>

int main( void ) {
	std::string brain = "HI THIS IS BRAIN";
	std::string anotherBrain = "HI THIS IS ANOTHER BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory adress of brain: " << &brain << std::endl;
	std::cout << "Memory adress held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory adress held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of brain: " << brain << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;

}