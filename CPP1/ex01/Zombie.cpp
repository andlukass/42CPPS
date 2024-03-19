#include "Zombie.hpp"
#include <iostream>
#include <sstream> 

void Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name ) {
	this->_name = name;
}

Zombie::Zombie( ) {

}

Zombie::Zombie( std::string name ) {
	this->_name = name;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " died" << std::endl;
}

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *horde = new Zombie[N];
	std::stringstream i_string;
	int i = -1;
	while ( ++i < N ){
		i_string.str("");
		i_string << i;
		horde[i].setName(name + i_string.str());
	}
	return horde;
}

