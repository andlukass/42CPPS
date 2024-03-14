#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name ) {
	Zombie randomZombie = Zombie(name);
	randomZombie.announce();
}