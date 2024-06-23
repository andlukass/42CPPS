#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);

void identify(Base* p);

void identify(Base& p);

static std::string MESSAGE = "The type of the class is: ";
