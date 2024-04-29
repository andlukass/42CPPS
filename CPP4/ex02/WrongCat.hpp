#pragma once

#include "WrongAnimal.hpp"

#include <string>
#include <iostream>

class WrongCat : public WrongAnimal{

	public:
		WrongCat();
		~WrongCat() ;

		void makeSound() const ;

};