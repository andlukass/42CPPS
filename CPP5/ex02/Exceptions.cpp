#include "Exceptions.hpp"

const char* GradeTooHighException::what() const _NOEXCEPT {
	return "Grade must be a number greater than 1";
}

const char* GradeTooLowException::what() const _NOEXCEPT {
	return "Grade must be a number lower than 150";
};
