#include "Span.hpp"

Span::Span() {
}

Span::~Span() {
}

Span::Span( const Span& toCopy ) {
	(void)toCopy;
}

Span& Span::operator=( const Span& toCopy ) {
	(void)toCopy;
	return *this;
}