#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>
#include <iostream>

class Cat : public Animal{
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& toCopy);
		Cat& operator=(const Cat& toCopy);
		~Cat();

		Brain* getBrain() const ;
		void makeSound() const ;

};