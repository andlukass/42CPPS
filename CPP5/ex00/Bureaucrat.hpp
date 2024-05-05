#pragma once

#include <string>
#include <iostream>
#include "Exceptions.hpp"

class Bureaucrat {
	protected:
		std::string _name;
		int _grade;

	public:

		GradeTooLowException lowException;
		GradeTooHighException highException;

		enum {
			GRADE_MAX = 1,
			GRADE_MIN = 150
		};

		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( const Bureaucrat &toCopy );
		Bureaucrat& operator=( const Bureaucrat &toCopy );

		std::string getName() const ;
		int getGrade() const ;
		void increment();
		void decrement();

};

 std::ostream& operator<<(std::ostream &out, Bureaucrat &b);