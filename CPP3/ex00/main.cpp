#include "ClapTrap.hpp"
#include <iomanip>

void print_div(const char *message) {
	std::cout << std::endl;
	std::cout << "┌────────────────────────────────┐"<< std::endl;
	std::cout << "│" << std::setw(21) << std::setfill(' ') << message << std::setw(14) << "│" << std::endl;
	std::cout << "└────────────────────────────────┘"<< std::endl;
}


int main (){
	print_div("CONSTRUCTORS");
	ClapTrap a("Cleber Tanide");
	ClapTrap b("Paulo Guedes");

	print_div("ACTIONS");
	int aDamage = 1;
	a.setAttackDamage(aDamage);
	a.attack("Paulo Guedes");
	b.takeDamage(aDamage);


	aDamage = 100;
	a.setAttackDamage(aDamage);
	a.attack("Paulo Guedes");
	b.takeDamage(aDamage);

	print_div("DESTRUCTORS");
}