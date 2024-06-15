#include "Intern.hpp"
	// void (Harl::*f[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};



Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern( const Intern &toCopy ) {
	*this = toCopy;
}

Intern& Intern::operator=( const Intern &toCopy ) {
	(void)toCopy;
	return *this;
}

AForm* Intern::newPresidential(std::string target){
	return new PresidentialPardonForm(target);
}
AForm* Intern::newShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}
AForm* Intern::newRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

std::string str_lower(std::string str){
	for (unsigned int i = 0; i < str.length(); ++i) {
		str[i] = std::tolower(str[i]);
	}
	return str;
}

AForm* Intern::makeForm( std::string name, std::string target ) {
	int i = 0;
	std::string options[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*f[])( std::string ) = {
		&Intern::newRobotomy, &Intern::newPresidential, &Intern::newShrubbery, 
	};

	while (str_lower(name) != options[i] && i < 3)
		i++;
	
	if (i != 3) {
		AForm *form = (this->*f[i])(target);
		std::cout << "Intern creates " << form->getName() << std::endl;
		return form;
	}
	std::cout << "Tried to create an invalid Form " << std::endl;
	return NULL;
}
