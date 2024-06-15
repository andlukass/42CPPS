#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
	private:
		AForm* newPresidential( std::string target );
		AForm* newShrubbery( std::string target );
		AForm* newRobotomy( std::string target );

	public:
		Intern();
		~Intern();
		Intern( const Intern &toCopy );
		Intern& operator=( const Intern &toCopy );

		AForm* makeForm( std::string name, std::string target );

};
