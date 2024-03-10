#include <iostream>
#include <cctype>

char *toUpperCase(char *str){
	int index = -1;

	while(str[++index])
		str[index] = toupper(str[index]);
	return str;
}

int main(int argc, char *argv[]){
	int index = 1;

	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	while(index < argc)
		std::cout << toUpperCase(argv[index++]);
	std::cout << std::endl;
	return 0;
}