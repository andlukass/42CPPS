#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

	public:
		Contact contacts[8];
		int index;

		PhoneBook();
};

#endif