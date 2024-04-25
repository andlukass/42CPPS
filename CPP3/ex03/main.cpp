#include "DiamondTrap.hpp"

#include <iomanip>

void print_div(const char *message) {
	std::cout << std::endl;
	std::cout << "┌────────────────────────────────┐"<< std::endl;
	std::cout << "│" << std::setw(21) << std::setfill(' ') << message << std::setw(14) << "│" << std::endl;
	std::cout << "└────────────────────────────────┘"<< std::endl;
}

int main (){

	print_div("CONSTRUCTORS");
	ClapTrap a("Cleber_Tanide");
	ScavTrap b("Paulo_Guedes");
	FragTrap c("Tadeu_Schmidt");
	DiamondTrap d( "Rodrigo_Faro" );


	print_div("ACTIONS");
	d.whoAmI();
	d.attack("Tadeu_Schmidt");

	a.attack("Paulo Guedes");

	b.attack("Cleber Tanide");

	c.attack("Paulo Guedes");

	print_div("DESTRUCTORS");
}

