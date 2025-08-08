#pragma once

#include <algorithm>
#include <cctype>
#include <climits>
#include <ctime>
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

#define MAX_PRINT 5

template <typename Container> class PmergeMe {
  private:
    bool _shortDisplay;
    double _timeTaken;
    Container _data;

    void binaryInsert(Container &container,
                      const typename Container::value_type &value);
    void parseAndStore(const std::string &numbers);
    std::string getTypeName() const;

  public:
    PmergeMe(const std::string &numbers, const bool &shortDisplay = false);
    ~PmergeMe();
    PmergeMe(const PmergeMe &toCopy);
    PmergeMe &operator=(const PmergeMe &toCopy);

    void printTimeTaken() const;
    void printContainer() const;
    void fordJohnson();
};