#include <PmergeMe.hpp>

static void printErrorMessage(char *argv[]) {
    std::cerr << "Error: Please provide a list of positive integers as "
                 "arguments. (Max 3000)"
              << std::endl;
    std::cerr << "Usage: " << argv[0] << "<number1> <number2> ... [-a]"
              << std::endl;
    std::cerr << "  -a: Show detailed output" << std::endl;
}

static std::pair<std::string, bool> processArguments(int argc, char *argv[]) {
    bool shortDisplay = true;

    std::stringstream oss;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-a") {
            shortDisplay = false;
            continue;
        }
        oss << " " << argv[i];
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

    if (numbers.empty()) {
        printErrorMessage(argv);
        return 1;
    }

    try {
        PmergeMe<std::vector<int> > vectorFord(numbers, shortDisplay);
        PmergeMe<std::deque<int> > dequeFord(numbers, shortDisplay);

        vectorFord.fordJohnson();
        dequeFord.fordJohnson();

        vectorFord.printContainer();

        dequeFord.printTimeTaken();
        vectorFord.printTimeTaken();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
