#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void addContact(Contact *contact){
	std::cout << "enter the contact first name: ";
	std::getline(std::cin, contact->firstName);

	std::cout << "enter the contact last name: ";
	std::getline(std::cin, contact->lastName);

	std::cout << "enter the contact nickname: ";
	std::getline(std::cin, contact->nickname);

	std::cout << "enter the contact number: ";
	std::getline(std::cin, contact->number);

	std::cout << "enter the contact darkest secret: ";
	std::getline(std::cin, contact->darkestSecret);
}

void searchContact(PhoneBook *phonebook){
	std::string input;

	std::cout << "type an index: ";
	std::getline(std::cin, input);
	(void)phonebook;
}

int main(){
	PhoneBook phonebook;
	std::string input;
	int index = 0;

	while (1)
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			addContact(&phonebook.contacts[index]);
		} else if (input == "SEARCH") {
			searchContact(&phonebook);
		} else if (input == "EXIT") {
			break;
		} else {
			std::cout << "wrong command!" << std::endl;
		}
		index++;
		if (index == 8)
			index = 0;
	}
	return 0;
}