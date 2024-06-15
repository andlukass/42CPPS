#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
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
		class NotSignedException : public std::exception{
				const char *what() const throw();
		};

		AForm();
		virtual ~AForm() = 0;
		AForm(std::string name, int _toExecute, int _toSign);
		AForm( const AForm &toCopy );
		AForm& operator=( const AForm &toCopy );

		std::string getName() const ;
		int getSignedStatus() const ;
		int getToExecute() const ;
		int getToSign() const ;

		void beSigned( Bureaucrat& b );
		virtual void execute(Bureaucrat const & executor) const = 0;

};

 std::ostream& operator<<(std::ostream &out, AForm &b);