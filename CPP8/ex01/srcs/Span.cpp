#include <Span.hpp>

Span::Span(unsigned int N) : _N(N) {
	_vec.reserve(N);
}

Span::~Span() {
	_vec.clear();
}

Span::Span( const Span& toCopy ) {
	_N = toCopy._N;
	_vec.clear();
	_vec.reserve(_N);
	_vec.assign(toCopy._vec.begin(), toCopy._vec.end());
}

Span& Span::operator=( const Span& toCopy ) {
	if (this == &toCopy)
		return *this;
	_N = toCopy._N;
	_vec.clear();
	_vec.reserve(_N);
	_vec.assign(toCopy._vec.begin(), toCopy._vec.end());
	return *this;
}

void Span::addNumber(int number) {
	if (_vec.size() >= _N)
		throw std::exception();
	_vec.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_vec.size() + std::distance(begin, end) > _N)
		throw std::exception();
	_vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw std::exception();
	std::vector<int> sortedVec = _vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	int shortest = sortedVec[1] - sortedVec[0];
	for (size_t i = 1; i < sortedVec.size(); i++) {
		if (sortedVec[i] - sortedVec[i - 1] < shortest)
			shortest = sortedVec[i] - sortedVec[i - 1];
	}
	return shortest;
}

int Span::longestSpan() {
	if (_vec.size() < 2)
		throw std::exception();
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}