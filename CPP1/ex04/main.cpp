#include <string>
#include <iostream>
#include <fstream>

std::string getFile(char *fileName){
	std::ifstream file(fileName);
	std::string input;
	std::string line;
	if (!file) {
		return input;
	}
	while (std::getline(file, line)) {
		input.append(line);
		if (!file.eof())
			input.append("\n");
	}
	file.close();
	return input;
}

std::string replacer(std::string input, std::string to_find, std::string to_replace){
	std::string replaced;

	long unsigned int i = input.find(to_find, 0);
	replaced += input.substr(0, i);
	input.erase(0, i + to_find.length());
	while (i != std::string::npos)
	{
		replaced += to_replace;
		i = input.find(to_find);
		replaced += input.substr(0, i);
		input.erase(0, i + to_find.length());
	}
	return replaced;
}

int saveToFile(std::string str, std::string fileName){
	std::ofstream file(fileName.c_str());
	if (!file)
		return 0;
	file << str;
	file.close();
	return 1;
}

int main(int argc, char *argv[]){
	std::string input;
	std::string finalFileName;

	if (argc != 4) {
		std::cout << "wrong arguments" << std::endl;
		return (1);
	}
	input = getFile(argv[1]);
	if (input.empty()){
		std::cout << "file empty or doesnt exist" << std::endl;
		return (2);
	}

	input = replacer(input, argv[2], argv[3]);
	finalFileName.append(argv[1] + std::string(".replace"));
	if (!saveToFile(input, finalFileName))
		std::cout << "error creating new file" << std::endl;
}
