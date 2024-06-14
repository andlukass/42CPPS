#include "Form.hpp"

Form::Form() : 
		_name("default"),
		_toExecute(150),
		_toSign(150),
		_isSigned(false){
}

Form::~Form() {
}

Form::Form(std::string name, int _toExecute, int _toSign) : 
							_name(name),
							_toExecute(_toExecute),
							_toSign(_toSign),
							_isSigned(false) {
	if (_toExecute < GRADE_MAX || _toSign  < GRADE_MAX) {
		throw Form::GradeTooHighException();
	}
	if (_toExecute > GRADE_MIN || _toSign  > GRADE_MIN) {
		throw Form::GradeTooLowException();
	}
}

Form::Form( const Form &toCopy ) : 
				_name(toCopy._name),
				_toExecute(toCopy._toExecute),
				_toSign(toCopy._toSign),
				_isSigned(toCopy._isSigned) {
}

Form& Form::operator=( const Form &toCopy ) {
	if (this == &toCopy) {
		return *this;
	}
	this->_isSigned = toCopy._isSigned;
	return *this;
}

std::string Form::getName() const {
	return this->_name;
}

int Form::getToExecute() const {
	return this->_toExecute;
}

int Form::getToSign() const {
	return this->_toSign;
}

int Form::getSignedStatus() const {
	return this->_isSigned;
}

void Form::beSigned( Bureaucrat& b ) {
	if (b.getGrade() >= this->_toSign) {
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

std::ostream& operator<<(std::ostream &out, Form &b) {
	std::string status = b.getSignedStatus() ? 
		"signed." : "not signed.";

	out << b.getName() << " Form.  " << b.getToExecute() << 
	" needed to execute. " << b.getToSign() << 
	" needed to sign. " << "Currently " << status ;
	return out;
}
