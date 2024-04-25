#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	DiamondTrap::_energyPoints = ScavTrap::_energyPoints;
	DiamondTrap::_hit = FragTrap::_hit;
	DiamondTrap::_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) {
	DiamondTrap::_name = name;
	ClapTrap::_name = name + "_clap_name";

	DiamondTrap::_energyPoints = ScavTrap::_energyPoints;
	DiamondTrap::_hit = FragTrap::_hit;
	DiamondTrap::_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap " << DiamondTrap::_name <<
	": name constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << DiamondTrap::_name <<
	" destructor called" << std::endl;
}

void DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void ){
	std::cout << "DiamondTrap " << DiamondTrap::_name <<
	" aka, " << ClapTrap::_name << std::endl;
}