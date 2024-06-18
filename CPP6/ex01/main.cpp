#include "Serializer.hpp"

#include <iostream>

int main () {
	uintptr_t toNumber;
	Data data;
	Data *newData;

	data.a = 97;
	data.b = 'a';
	data.c = NULL;

	std::cout << "\n\naddress before convertion:\t" << &data << std::endl;
	toNumber = Serializer::serialize(&data);
	newData = Serializer::deserialize(toNumber);
	std::cout << "address after convertion:\t" << newData << std::endl;
	std::cout << std::endl;

	std::cout << "VALUES FROM STRUCT:" << std::endl;
	std::cout << newData->a << "\t-\t" << data.a << std::endl;
	std::cout << newData->b << "\t-\t" << data.b << std::endl;
	std::cout << newData->c << "\t-\t" << data.c << std::endl;
	std::cout << std::endl;

}