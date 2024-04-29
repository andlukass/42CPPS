#pragma once

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		virtual ~Animal() = 0;
		Animal( const Animal &toCopy );
		Animal& operator=( const Animal &toCopy );

		std::string getType() const ;
		virtual void makeSound() const ;

};