#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		const int _toExecute;
		const int _toSign;
		bool _isSigned;

		class GradeTooLowException : public std::exception{
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
				const char *what() const throw();
		};

	public:

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