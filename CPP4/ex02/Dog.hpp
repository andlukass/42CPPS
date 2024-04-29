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
		Dog(const Dog& toCopy);
		Dog& operator=(const Dog& toCopy);
		~Dog() ;

		Brain* getBrain() const ;
		void makeSound() const ;

};