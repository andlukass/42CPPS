#include "AForm.hpp"

AForm::AForm() : 
		_name("default"),
		_toExecute(150),
		_toSign(150),
		_isSigned(false){
}

AForm::~AForm() {
}

AForm::AForm(std::string name, int _toExecute, int _toSign) : 
							_name(name),
							_toExecute(_toExecute),
							_toSign(_toSign),
							_isSigned(false) {
	if (_toExecute < GRADE_MAX || _toSign  < GRADE_MAX) {
		throw AForm::GradeTooHighException();
	}
	if (_toExecute > GRADE_MIN || _toSign  > GRADE_MIN) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm( const AForm &toCopy ) : 
				_name(toCopy._name),
				_toExecute(toCopy._toExecute),
				_toSign(toCopy._toSign),
				_isSigned(toCopy._isSigned) {
}

AForm& AForm::operator=( const AForm &toCopy ) {
	if (this == &toCopy) {
		return *this;
	}
	this->_isSigned = toCopy._isSigned;
	return *this;
}

std::string AForm::getName() const {
	return this->_name;
}

int AForm::getToExecute() const {
	return this->_toExecute;
}

int AForm::getToSign() const {
	return this->_toSign;
}

int AForm::getSignedStatus() const {
	return this->_isSigned;
}

void AForm::beSigned( Bureaucrat& b ) {
	if (b.getGrade() >= this->_toSign) {
		throw AForm::GradeTooLowException();
	}
	this->_isSigned = true;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}
const char* AForm::NotSignedException::what() const throw() {
	return "form is not signed";
}

std::ostream& operator<<(std::ostream &out, AForm &b) {
	std::string status = b.getSignedStatus() ? 
		"signed." : "not signed.";

	out << b.getName() << ".  " << b.getToExecute() << 
	" needed to execute. " << b.getToSign() << 
	" needed to sign. " << "Currently " << status ;
	return out;
}
