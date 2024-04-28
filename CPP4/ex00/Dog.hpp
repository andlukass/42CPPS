#pragma once

#include "Animal.hpp"

#include <string>
#include <iostream>

class Dog : public Animal{

	public:
		Dog();
		~Dog() ;

		void makeSound() const ;

};