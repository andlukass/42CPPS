#pragma once

#include <string>
#include <iostream>

class Brain {
	protected:
		std::string ideas[100];

	public:
		Brain();
		virtual ~Brain();
		Brain( std::string idea );
		Brain( const Brain &toCopy );
		Brain& operator=( const Brain &toCopy );

		std::string getIdea(int index) const ;

};