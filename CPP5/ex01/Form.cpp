#include "Form.hpp"

Form::Form() : 
		_toExecute(150),
		_isSigned(false),
		_toSign(150),
		_name("..."){
}

Form::~Form() {
}

Form::Form(std::string name, int _toExecute, int _toSign) : 
							_toExecute(_toExecute),
							_isSigned(false),
							_toSign(_toSign),
							_name(_name) {
	if (_toExecute < GRADE_MAX || _toSign  < GRADE_MAX) {
		throw this->lowException;
	}
	if (_toExecute < GRADE_MIN || _toSign  < GRADE_MIN) {
		throw this->highException;
	}
}

Form::Form( const Form &toCopy ) : 
				_toExecute(toCopy._toExecute),
				_isSigned(toCopy._isSigned),
				_toSign(toCopy._toSign),
				_name(toCopy._name) {
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
	return this->_toSign;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_toSign) {
		std::cout << b.getName() << " couldn't sign " <<
		this->_name << " because the grade is too low." << std::endl;
		throw this->lowException;
	}
	this->_isSigned = true;
	std::cout << b.getName() << " signed " << this->_name << std::endl;
}

std::ostream& operator<<(std::ostream &out, Form &b) {
	std::string status;
	status = "Is signed.";
	if (!b.getSignedStatus()) {
		status = "Is not signed.";
	}
	out << b.getName() << " Form.  " << b.getToExecute() << 
	" needed to execute. " << b.getToSign() << 
	" needed to sign. " << status ;
	return out;
}
