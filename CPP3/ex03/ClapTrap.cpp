#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_hit = 10;
}

ClapTrap::ClapTrap( std::string name ) {
	this->_name = name;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_hit = 10;
	std::cout << "ClapTrap " << this->_name << ": name constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &toCopy ){
	this->_name = toCopy._name;
	this->_attackDamage = toCopy._attackDamage;
	this->_energyPoints = toCopy._energyPoints;
	this->_hit = toCopy._hit;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &toCopy ){
	this->_name = toCopy._name;
	this->_attackDamage = toCopy._attackDamage;
	this->_energyPoints = toCopy._energyPoints;
	this->_hit = toCopy._hit;
	return *this;
}

void ClapTrap::setAttackDamage(unsigned int amount){
	this->_attackDamage = amount;
}

void ClapTrap::attack( const std::string& target ) {
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << 
		" dont have enough energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name <<
	" attacks " << target << " causing " <<
	this->_attackDamage << " point(s) of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if ( this->_hit <= amount ) {
		this->_hit = 0;
	} else {
		this->_hit -= amount;
	}
	if (this->_hit <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name <<
		" dont have enough energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name <<
	" repaired itself in: " << amount << std::endl;
	this->_hit += amount;
	this->_energyPoints -= 1;
}