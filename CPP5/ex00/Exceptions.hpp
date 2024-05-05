#pragma once

#include <string>
#include <iostream>
#include <exception>

class GradeTooHighException : public std::exception {
	public: const char* what() const _NOEXCEPT ;
};

class GradeTooLowException : public std::exception {
	public: const char* what() const _NOEXCEPT ;
};