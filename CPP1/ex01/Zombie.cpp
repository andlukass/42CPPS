#include "Zombie.hpp"
#include <iostream>

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
	int i = -1;
	while ( ++i < N )
		horde[i].setName(name + std::to_string(i));
	return horde;
}

