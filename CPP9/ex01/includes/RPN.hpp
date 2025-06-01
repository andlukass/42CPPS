#pragma once

#include <stack>
#include <string>
#include <sstream>

class RPN {
	private:
		std::stack<int> _numbers;
		std::stack<char> _operators;
		std::string _expression;
		bool _isCalculated;
		int _result;

		void applyOperator(char op);
		bool isOperator(std::string token);
		void clearStacks();

	public:
		RPN(const std::string& expression);
		~RPN();
		RPN( const RPN& toCopy);
		RPN& operator=( const RPN& toCopy);

		void calculate();
		int getResult() const;
};