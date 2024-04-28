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
		~Cat();

		Brain* getBrain() const ;
		void makeSound() const ;


};