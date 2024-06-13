#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < GRADE_MAX) {
		throw this->lowException;
	}
	if (grade > GRADE_MIN) {
		throw this->highException;
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
		throw this->highException;
	}
	this->_grade--;
}

void Bureaucrat::decrement() {
	if (this->_grade + 1 == 151) {
		throw this->lowException;
	}
	this->_grade++;
}

void Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " <<
		f.getName() << " because " << e.what() << std::endl;
	}
	std::cout << this->_name << " signed " << f.getName() << std::endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
