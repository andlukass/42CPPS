#include <RPN.hpp>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./RPN <expression>" << std::endl;
        return 1;
    }
    try {
        RPN rpn = RPN(argv[1]);
        rpn.calculate();
        std::cout << rpn.getResult() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}