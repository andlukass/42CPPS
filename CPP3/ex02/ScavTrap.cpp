#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_hit = 100;
}

ScavTrap::ScavTrap( std::string name ) {
	this->_name = name;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_hit = 100;
	std::cout << "ScavTrap " << this->_name << ": name constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack( const std::string& target ) {
	if (this->_energyPoints <= 0) {
		std::cout << "ScavTrap " << this->_name << 
		" dont have enough energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name <<
	" attacks " << target << " causing " <<
	this->_attackDamage << " point(s) of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ScavTrap::guardGate( void ){
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}