#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
			AForm("Presidential Pardon", 5, 25) {
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : 
			AForm("Presidential Pardon", 5, 25) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &toCopy ) :
			AForm("Presidential Pardon", 5, 25) {
	*this = toCopy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &toCopy ) {
	if (this == &toCopy) {
		return *this;
	}
	this->_target = toCopy._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignedStatus()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << this->_target <<
	" has been pardoned by Zaphod Beeblebrox" << std::endl;
}
