#include "easyfind.hpp"
#include <vector>

int main () {

	std::vector<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	try {

		std::cout << *(easyfind(a, 5)) << std::endl;
		std::cout << *(easyfind(a, 15)) << std::endl;

	} catch (std::exception &e) {
		std::cout << "element does not exist inside the container" << std::endl;
	}

	return 0;

}