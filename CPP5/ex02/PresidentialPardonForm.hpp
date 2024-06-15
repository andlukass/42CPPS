#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm &toCopy );
		PresidentialPardonForm& operator=( const PresidentialPardonForm &toCopy );

		void execute(Bureaucrat const & executor) const;
};