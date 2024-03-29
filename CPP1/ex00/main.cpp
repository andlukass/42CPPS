#include "Zombie.hpp"
#include <iostream>

int main( void ){

	Zombie z1 = Zombie("vasconcelos");
	z1.announce();

	Zombie *z2 = newZombie("bruno");
	z2->announce();

	randomChump("cleber");

	delete z2;
}
