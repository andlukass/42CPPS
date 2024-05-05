#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < GRADE_MAX) {
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade > GRADE_MIN) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade = grade;
}
Bureaucrat::Bureaucrat( const Bureaucrat &toCopy ) {
	*this = toCopy;
}
Bureaucrat& Bureaucrat::operator=( const Bureaucrat &toCopy ) {
	if (this == &toCopy) {
		return *this;
	}
	this->_grade = toCopy._grade;
	this->_name = toCopy._name;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increment() {
	if (this->_grade - 1 == 0) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrement() {
	if (this->_grade + 1 == 151) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
	return "Grade must be a number greater than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
	return "Grade must be a number lower than 150";
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
