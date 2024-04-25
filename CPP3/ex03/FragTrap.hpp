#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap();
		FragTrap( std::string name );
		virtual ~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys( void );

};