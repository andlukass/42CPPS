#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
			AForm("Robotomy Request", 45, 72) {
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : 
			AForm("Robotomy Request", 45, 72) {
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &toCopy ) :
			AForm("Robotomy Request", 45, 72) {
	*this = toCopy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &toCopy ) {
	if (this == &toCopy) {
		return *this;
	}
	this->_target = toCopy._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSignedStatus()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getToExecute()) {
		throw AForm::GradeTooLowException();
	}
	srand(time(0));
	std::cout << "drrrrrr...drrrrrrrr...drrrrrrr" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized" << std::endl;
	} else {
		std::cout << this->_target << " robotomy failed." << std::endl;
	}
}
