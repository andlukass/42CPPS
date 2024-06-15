#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm &toCopy );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm &toCopy );

		void execute(Bureaucrat const & executor) const;
};