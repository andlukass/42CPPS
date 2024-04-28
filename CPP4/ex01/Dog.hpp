#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>
#include <iostream>

class Dog : public Animal{
	private:
		Brain* _brain;

	public:
		Dog();
		~Dog() ;

		void makeSound() const ;

};