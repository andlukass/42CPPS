#include "Zombie.hpp"
#include <iostream>

int main( void ){
	Zombie *horde = zombieHorde(10, "joao");

	for (int i = 0; i < 10 ; i++) {
		horde[i].announce();
	}

	delete []horde;
	return 0;
}
