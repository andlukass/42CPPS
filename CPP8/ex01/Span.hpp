#pragma once

class Span {
	private:


	public:
		Span();
		~Span();
		Span( const Span& toCopy);
		Span& operator=( const Span& toCopy);
};