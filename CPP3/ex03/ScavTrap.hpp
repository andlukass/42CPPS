#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		unsigned int _energyPoints;

	public:
		ScavTrap();
		ScavTrap( std::string name );
		virtual ~ScavTrap();

		void attack(const std::string& target);
		void guardGate( void );

};