#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& src);
		MateriaSource& operator=( const MateriaSource& src);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};