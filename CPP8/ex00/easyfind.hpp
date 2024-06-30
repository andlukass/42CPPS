#pragma once

#include <iostream>
#include <string>
#include <algorithm>

template< typename T >
typename T::iterator easyfind(T& a, int b) {
	if (std::find(a.begin(), a.end(), b) == a.end()) {
		throw std::exception();
	}
	return std::find(a.begin(), a.end(), b);
}
