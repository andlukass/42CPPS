#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm &toCopy );
		RobotomyRequestForm& operator=( const RobotomyRequestForm &toCopy );

		void execute(Bureaucrat const & executor) const;
};