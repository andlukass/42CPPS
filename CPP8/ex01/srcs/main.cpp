#include <Span.hpp>
#include <iostream>

const int SIZE = 10000;

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    std::cout << "--------------------------------" << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < SIZE; i++)
        vec.push_back(i);

    Span sp2 = Span(SIZE);
    sp2.addNumber(vec.begin(), vec.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    return 0;
}