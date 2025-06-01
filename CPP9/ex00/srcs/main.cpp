#include <BitcoinExchange.hpp>
#include <iostream>
#include <string>

int main (int argc, char **argv) {
    (void)(argv);
    if (argc != 2) {
        std::cout << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    try {
        Btc btc("./data.csv");
        // btc.printDatabase();
        btc.parseInput(argv[1]);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}