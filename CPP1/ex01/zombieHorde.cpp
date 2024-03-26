#include "Zombie.hpp"
#include <sstream> 

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
