#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
			AForm("Shrubbery Creation", 137, 145) {
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : 
			AForm("Shrubbery Creation", 137, 145) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm &toCopy ) :
			AForm("Shrubbery Creation", 137, 145) {
	*this = toCopy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &toCopy ) {
	if (this == &toCopy) {
		return *this;
	}
	this->_target = toCopy._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignedStatus()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::string tree =
		"   *        *        *\n"
		"  ***      ***      ***\n"
		" *****    *****    *****\n"
		"*******  *******  *******\n"
		"  |||      |||      |||\n";
	std::ofstream file((this->_target + "_shrubbery").c_str());
	file << tree << std::endl;
	file.close();
}
