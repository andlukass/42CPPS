#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal( const WrongAnimal &toCopy );
		WrongAnimal& operator=( const WrongAnimal &toCopy );

		std::string getType() const ;
		void makeSound() const ;

};