#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		const int _toExecute;
		const int _toSign;
		bool _isSigned;

	public:
		class GradeTooLowException : public std::exception{
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
				const char *what() const throw();
		};

		Form();
		~Form();
		Form(std::string name, int _toExecute, int _toSign);
		Form( const Form &toCopy );
		Form& operator=( const Form &toCopy );

		std::string getName() const ;
		int getSignedStatus() const ;
		int getToExecute() const ;
		int getToSign() const ;

		void beSigned( Bureaucrat& b );

};

 std::ostream& operator<<(std::ostream &out, Form &b);