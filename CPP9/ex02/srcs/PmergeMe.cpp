#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe<Container>::binaryInsert(
    Container &container, const typename Container::value_type &value) {
    typename Container::iterator it =
        std::lower_bound(container.begin(), container.end(), value);
    container.insert(it, value);
}

template <typename Container>
void PmergeMe<Container>::parseAndStore(const std::string &numbers) {
    std::istringstream input(numbers);
    std::string token;
    _data.clear();

    while (input >> token) {
        // validate token contains only optional leading '+' and digits
        size_t pos = 0;
        if (!token.empty() && (token[0] == '+' || token[0] == '-'))
            pos = 1;

        if ((pos == 1 && token[0] == '-') || (pos >= token.size()))
            throw std::invalid_argument("Error: invalid token");

        for (size_t i = pos; i < token.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(token[i])))
                throw std::invalid_argument("Error: invalid token");
        }

        // convert and range-check
        long long value = 0;
        {
            std::istringstream conv(token);
            conv >> value;
            if (conv.fail())
                throw std::invalid_argument("Error: invalid token");
        }
        if (value < 0)
            throw std::invalid_argument("Error: negative number");
        if (value > INT_MAX)
            throw std::out_of_range("Error: number too large");

        int intValue = static_cast<int>(value);

        _data.push_back(intValue);
    }

    if (this->_data.size() > 3000) {
        throw std::invalid_argument("Error: list too large");
    }
}

template <typename Container>
std::string PmergeMe<Container>::getTypeName() const {
    std::string typeName = typeid(Container).name();

    if (typeName.find("vector") != std::string::npos)
        return "vector";
    if (typeName.find("deque") != std::string::npos)
        return "deque";
    if (typeName.find("list") != std::string::npos)
        return "list";

    return typeName;
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const std::string &numbers,
                              const bool &shortDisplay)
    : _shortDisplay(shortDisplay), _timeTaken(-1), _data() {
    parseAndStore(numbers);
}

template <typename Container> PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &toCopy)
    : _shortDisplay(toCopy._shortDisplay), _timeTaken(toCopy._timeTaken),
      _data(toCopy._data) {}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &toCopy) {
    if (this != &toCopy) {
        _shortDisplay = toCopy._shortDisplay;
        _timeTaken = toCopy._timeTaken;
        _data = toCopy._data;
    }
    return *this;
}

template <typename Container> void PmergeMe<Container>::printTimeTaken() const {
    if (this->_timeTaken < 0) {
        throw std::logic_error("Error: still not sorted");
    }
    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Time to process a range of " << this->_data.size()
              << " elements with std::" << getTypeName() << " : "
              << this->_timeTaken << "s" << std::endl;
}

template <typename Container> void PmergeMe<Container>::printContainer() const {
    if (this->_shortDisplay) {
        for (size_t i = 0; i < this->_data.size() && i < MAX_PRINT; ++i)
            std::cout << this->_data[i] << " ";
        if (this->_data.size() > MAX_PRINT)
            std::cout << "[...]";
    } else {
        for (size_t i = 0; i < this->_data.size(); ++i)
            std::cout << this->_data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Container> void PmergeMe<Container>::fordJohnson() {
    std::vector<std::pair<int, int> > pairs;
    Container mainChain;
    Container pending;
    clock_t start = clock();

    // 1. make the pairs
    for (size_t i = 0; i + 1 < this->_data.size(); i += 2) {
        int a = this->_data[i];
        int b = this->_data[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    // if its odd add sentinel
    if (this->_data.size() % 2 != 0)
        pairs.push_back(std::make_pair(this->_data.back(), -1));

    // 2. split both chains
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        if (pairs[i].second != -1)
            pending.push_back(pairs[i].second);
    }

    // 3. sort highest numbers
    std::sort(mainChain.begin(), mainChain.end());

    // 4. insert lowers with binary search
    for (size_t i = 0; i < pending.size(); ++i) {
        binaryInsert(mainChain, pending[i]);
    }

    clock_t end = clock();
    this->_timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
}

// Explicit template instantiations for common containers
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
