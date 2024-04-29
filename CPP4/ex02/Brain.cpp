#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain: destructor called" << std::endl;
}

Brain::Brain( std::string idea ) {
	std::cout << "Brain: idea constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = idea;
	}
}

Brain::Brain( const Brain &toCopy ) {
	*this = toCopy;
}

Brain& Brain::operator=( const Brain &toCopy ) {
	if (this == &toCopy)
		return (*this);
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = toCopy.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index > 99)
		return "not a valid index idea";
	return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index > 99)
		return ;
	this->ideas[index] = idea;
}
