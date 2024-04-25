#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_hit = 100;
}

FragTrap::FragTrap( std::string name ) {
	this->_name = name;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_hit = 100;
	std::cout << "FragTrap " << this->_name << ": name constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

void FragTrap::attack( const std::string& target ) {
	if (this->_energyPoints <= 0) {
		std::cout << "FragTrap " << this->_name << 
		" dont have enough energy points" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name <<
	" attacks " << target << " causing " <<
	this->_attackDamage << " point(s) of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void FragTrap::highFivesGuys( void ){
	std::cout << "FragTrap " << this->_name << " asked for a high five" << std::endl;
}