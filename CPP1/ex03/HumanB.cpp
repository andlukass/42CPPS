#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB( void ) {
	std::cout << this->_name << " died" << std::endl;
}

void HumanB::attack( void ) {
	if (this->_weapon) {
		std::cout << this->_name << " attacks with their " \
		<< this->_weapon->getType() << std::endl;
	} else {
		std::cout << this->_name << " doesnt have a weapon to attack" << std::endl;
	}
}

void HumanB::setWeapon( Weapon &weapon ) {
	this->_weapon = &weapon;
}
