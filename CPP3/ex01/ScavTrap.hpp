#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate( void );

};