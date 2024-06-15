#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default") {
	this->_grade = 150;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < GRADE_MAX) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > GRADE_MIN) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}
Bureaucrat::Bureaucrat( const Bureaucrat &toCopy ) : _name(toCopy._name) {
	*this = toCopy;
}
Bureaucrat& Bureaucrat::operator=( const Bureaucrat &toCopy ) {
	if (this == &toCopy) {
		return *this;
	}
	this->_grade = toCopy._grade;
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

void Bureaucrat::signForm( AForm &form ) {
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign "
		<< form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " signed "
	<< form.getName() << std::endl;
}

void Bureaucrat::executeForm( AForm &form ) {
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't execute "
		<< form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " executed "
	<< form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
