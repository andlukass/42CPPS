#pragma once

#include "AMateria.hpp"

class Character : public ICharacter
{
	protected:
		AMateria *_materias[4];
		std::string _name;
		int _index;

	public:
		Character();
		Character(std::string const& name);
		Character( const Character& src);
		Character& operator=( const Character& src);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		// void unequip(int idx);
		void use(int idx, ICharacter& target);
};