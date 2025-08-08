#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

#include <PmergeMe.hpp>

void printErrorMessage(char *argv[]) {
    std::cerr
        << "Error: Please provide a list of positive integers as arguments."
        << std::endl;
    std::cerr << "Usage: " << argv[0] << "<number1> <number2> ... [-a]"
              << std::endl;
    std::cerr << "  -a: Show detailed output (default: short output)"
              << std::endl;
}

std::pair<std::string, bool> processArguments(int argc, char *argv[]) {
    bool shortDisplay = true;

    // Convert command line arguments to a single string, filtering out -a flag
    std::ostringstream oss;
    bool firstNumber = true;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-a") {
            shortDisplay = false;
            continue; // Skip the -a flag
        }

        if (!firstNumber)
            oss << " ";
        oss << argv[i];
        firstNumber = false;
    }
    std::string numbers = oss.str();

    return std::make_pair(numbers, shortDisplay);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printErrorMessage(argv);
        return 1;
    }

    std::pair<std::string, bool> result = processArguments(argc, argv);
    std::string numbers = result.first;
    bool shortDisplay = result.second;

    // Check if we have any numbers after processing flags
    if (numbers.empty()) {
        printErrorMessage(argv);
        return 1;
    }

    try {
        PmergeMe<std::vector<int> > vectorFord(numbers, shortDisplay);
        PmergeMe<std::deque<int> > dequeFord(numbers, shortDisplay);

        vectorFord.fordJohnsonSimple();
        dequeFord.fordJohnsonSimple();

        vectorFord.printContainer();

        dequeFord.printTimeTaken();
        vectorFord.printTimeTaken();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
