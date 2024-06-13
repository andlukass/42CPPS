#pragma once

#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		const int _toExecute;
		const int _toSign;
		bool _isSigned;

	public:

		GradeTooLowException lowException;
		GradeTooHighException highException;

		enum {
			GRADE_MAX = 1,
			GRADE_MIN = 150
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

		void beSigned(Bureaucrat& b) ;
		

};

 std::ostream& operator<<(std::ostream &out, Form &b);