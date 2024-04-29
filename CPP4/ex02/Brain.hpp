#pragma once

#include <string>
#include <iostream>

class Brain {
	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain( std::string idea );
		Brain( const Brain &toCopy );
		Brain& operator=( const Brain &toCopy );

		std::string getIdea(int index) const ;
		void setIdea(int index, std::string idea) ;


};