#pragma once

#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer( const Serializer& toCopy);
		Serializer& operator=( const Serializer& toCopy);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};