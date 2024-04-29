#include "Ice.hpp"
#include "Character.hpp"

int main(){
	AMateria* ice = new Ice;
	Character me("lucas");
	Character enemy("hitler");

	me.equip(ice);

	me.use(0, enemy);
	

	

}