#pragma once

#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name = 0;
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

		AForm();
		~AForm();
		AForm(std::string name, int _toExecute, int _toSign);
		AForm( const AForm &toCopy );
		AForm& operator=( const AForm &toCopy );

		std::string getName() const ;
		int getSignedStatus() const ;
		int getToExecute() const ;
		int getToSign() const ;

		void beSigned(Bureaucrat& b) ;
		

};

 std::ostream& operator<<(std::ostream &out, AForm &b);