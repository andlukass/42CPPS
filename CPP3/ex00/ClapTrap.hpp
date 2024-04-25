#pragma once

#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		unsigned int _hit;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap( const ClapTrap &toCopy );
		ClapTrap& operator=( const ClapTrap &toCopy );

		void setAttackDamage(unsigned int amount);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};