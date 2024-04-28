#pragma once

#include "Animal.hpp"

#include <string>
#include <iostream>

class Cat : public Animal{

	public:
		Cat();
		~Cat() ;

		void makeSound() const ;

};