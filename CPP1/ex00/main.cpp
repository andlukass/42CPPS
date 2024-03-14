#include "Zombie.hpp"
#include <iostream>

int main( void ){

	Zombie z1 = Zombie("vasconcelos");
	z1.announce();

	Zombie *z2 = newZombie("bruno");
	z2->announce();

	randomChump("cleber");

	z2->~Zombie();
}

/*
Zombie teste(){
	Zombie test = Zombie("rogerio");
	return test;
}
int main(){
	Zombie z1 = teste();
	z1.announce();
}

diff:
	Zombie test = Zombie("rogerio");
	Zombie test2 = &test;

	Zombie teste = new Zombie("anastacio");

*/