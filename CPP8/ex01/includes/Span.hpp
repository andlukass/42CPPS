#pragma once

#include <vector>
#include <algorithm>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _vec;

	public:
		Span(unsigned int N);
		~Span();
		Span( const Span& toCopy);
		Span& operator=( const Span& toCopy);

		void addNumber(int number);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};