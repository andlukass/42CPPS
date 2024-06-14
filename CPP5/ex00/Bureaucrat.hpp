#pragma once

#include <string>
#include <iostream>

#include <exception>

enum {
	GRADE_MAX = 1,
	GRADE_MIN = 150
};

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

		class GradeTooLowException : public std::exception{
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
				const char *what() const throw();
		};

	public:
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