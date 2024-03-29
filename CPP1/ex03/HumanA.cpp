#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon &weapon ) : _weapon(weapon) {
	this->_name = name;
}

HumanA::~HumanA( void ) {
	std::cout << this->_name << " died" << std::endl;
}

void HumanA::attack( void ) {
	std::cout << this->_name << " attacks with their " \
	<< this->_weapon.getType() << std::endl;
}