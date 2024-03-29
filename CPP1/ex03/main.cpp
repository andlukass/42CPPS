#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

int main() {
	Weapon hammer = Weapon("medieval hammer");

	const std::string &weaponREF = hammer.getType();
	std::cout << "const hammer type: " << weaponREF << std::endl;
	// weaponREF = NULL;

	HumanA jonas = HumanA("jonas", hammer);
	jonas.attack();

	HumanB marcos = HumanB("marcos");
	marcos.setWeapon(hammer);
	marcos.attack();

	hammer.setType("wood hammer");
	marcos.attack();

	std::cout << "\n**-----DESTRUCTORS-----**" << std::endl;
}