#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <vector>

int main(){
	/*MAIN TESTS*/
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		// src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	/*UNEQUIP TESTS*/
	// {
	// 	std::vector<AMateria*> floorMaterias;

	// 	MateriaSource src;
	// 	src.learnMateria(new Ice());

	// 	Character me("me");
	// 	me.equip(src.createMateria("ice"));

	// 	floorMaterias.push_back(me.getEquip(0));
	// 	me.unequip(0);

	// 	me.use(0, me);

	// 	for (unsigned long i = 0; i < floorMaterias.size(); i++)
	// 		if (floorMaterias[i])
	// 			delete floorMaterias[i];
	// }

	// /*COPY CHARACTER TESTS*/
	// {
	// 	MateriaSource src;
	// 	src.learnMateria(new Ice());
	// 	Character bob = Character("bob");
	// 	Character jonas = Character("jonas");
	// 	Character george;
	// 	george.equip(src.createMateria("ice"));
	// 	george.equip(src.createMateria("ice"));
	// 	jonas.equip(src.createMateria("ice"));
	// 	george = jonas;
	// 	std::cout << "___________________" << std::endl;
	// 	jonas.use(0, bob);
	// 	george.use(0, bob);
	// 	george.use(1, bob);
	// }

	// /*COPY MATERIASOURCE TESTS*/
	// {
	// 	MateriaSource src;
	// 	src.learnMateria(new Ice());
	// 	MateriaSource src2;
	// 	src2 = src;
	// 	Character bob = Character("bob");
	// 	bob.equip(src.createMateria("ice"));
	// 	bob.equip(src2.createMateria("ice"));
	// 	bob.use(0, bob);
	// }

	/*COPY MATERIA TESTS*/
	// {
	// 	Ice *ice = new Ice();
	// 	Ice *ice2 = new Ice();
	// 	*ice2 = *ice;
	// 	delete ice2;
	// 	delete ice;
	// }

	return 0;

}