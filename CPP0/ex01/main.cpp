#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string truncateString(std::string str){
	if (str.length() <= 10)
		return str;
	else
		return str.substr(0, 10 - 1) + ".";
}
void printLine(void){
	std::cout << "+" << std::right << std::setfill('-') << std::setw(44) << "+" << std::endl;
}
void printTitles(void){
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << "index";
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << "first name";
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << "last name";
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << "nickname";
	std::cout << "|" << std::endl;
}
void printContact(Contact contact, int index){
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << index;
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << truncateString(contact.firstName);
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << truncateString(contact.lastName);
	std::cout << "|" << std::setw(10) << std::setfill(' ') << std::right << truncateString(contact.nickname);
	std::cout << "|" << std::endl;
}
void printContactInfo(Contact *contacts, int input, int last){
	if (input == -1 || input >= last)
		std::cout << "not a valid index" << std::endl;
	else {
		std::cout << "First Name: " << contacts[input].firstName << std::endl;
		std::cout << "Last Name: " << contacts[input].lastName << std::endl;
		std::cout << "Nickname: " << contacts[input].nickname << std::endl;
		std::cout << "Number: " << contacts[input].number << std::endl;
		std::cout << "darkest Secret: " << contacts[input].darkestSecret << std::endl;
	}
}

int getIndex(void){
	std::string input;

	std::getline(std::cin, input);
	for (int i = 0; input[i]; i++) {
		if (!std::isdigit(input[i]))
			return -1;
	}
	if (input.length() > 1)
		return -1;
	return (input[0] - '0');
}

void searchContact(PhoneBook *phonebook, int index){
	int last = phonebook->isFull ? 8 : index;
	int i = -1;
	int input;

	printLine();
	if (!phonebook->isFull && last == 0)
		std::cout << "|" << std::setw(43) << std::setfill(' ') << std::left << "no contacts yet..." << "|" << std::endl;
	else {
		printTitles();
		while (++i < last)
			printContact(phonebook->contacts[i], i);
	}
	printLine();
	std::cout << "type an index: ";
	input = getIndex();
	printContactInfo(phonebook->contacts, input, last);

}

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

int main(){
	PhoneBook phonebook;
	std::string input;
	int index = 0;

	while (1)
	{
		std::cout << "phonebook> ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			addContact(&phonebook.contacts[index++]);
			if (index == 8){
				phonebook.isFull = true;
				index = 0;
			}
		} else if (input == "SEARCH") {
			searchContact(&phonebook, index);
		} else if (input == "EXIT") {
			break;
		} else {
			std::cout << "wrong command!" << std::endl;
		}
	}
	return 0;
}