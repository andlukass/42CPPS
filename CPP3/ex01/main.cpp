#include "ClapTrap.hpp"

int main (){
	ClapTrap a("manuel");
	ClapTrap b("miguel");

	a.setAttackDamage(1);
	a.attack("miguel");
	b.takeDamage(1);

	a.setAttackDamage(100);
	a.attack("miguel");
	b.takeDamage(100);

}