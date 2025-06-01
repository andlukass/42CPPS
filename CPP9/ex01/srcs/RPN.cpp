#include <RPN.hpp>
#include <iostream>

RPN::RPN(const std::string& expression) {
    this->_expression = expression;
    this->_isCalculated = false;
}

RPN::~RPN() {
    this->clearStacks();
}

RPN::RPN( const RPN& toCopy ) {
    this->clearStacks();
    this->_expression = toCopy._expression;
    this->_numbers = toCopy._numbers;
    this->_operators = toCopy._operators;
}

RPN& RPN::operator=( const RPN& toCopy ) {
    if (this == &toCopy)
        return *this;
    this->clearStacks();
    this->_expression = toCopy._expression;
    this->_numbers = toCopy._numbers;
    this->_operators = toCopy._operators;
    return *this;
}

bool RPN::isOperator(std::string token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::applyOperator(char op) {
    int a = this->_numbers.top();
    this->_numbers.pop();
    int b = this->_numbers.top();
    this->_numbers.pop();
    if (b == 0 && op == '/') {
        throw std::invalid_argument("Division by zero: " + std::to_string(b) + " / " + std::to_string(a));
    }
    switch (op) {
        case '+':
            this->_numbers.push(a + b);
            break;
        case '-':
            this->_numbers.push(b - a); 
            break;
        case '*':
            this->_numbers.push(a * b);
            break;
        case '/':
            this->_numbers.push(b / a);
            break;
    }
    this->_operators.pop();
}

static int strToInt(const std::string& token) {
    std::istringstream iss(token);
    int number;
    iss >> number;

    if (iss.fail()) {
        throw std::invalid_argument("Invalid token: " + token);
    }

    char remaining;
    if (iss >> remaining) {
        throw std::invalid_argument("Invalid token: " + token);
    }

    return number;
}

void RPN::calculate() {
    this->clearStacks();

    std::stringstream ss(this->_expression);
    std::string token;
    while (ss >> token) {
        if (ss.fail()) {
            throw std::invalid_argument("Invalid token: " + token);
        }
        if (isOperator(token)) {
            this->_operators.push(token[0]);
            if (this->_numbers.size() >= 2) {
                this->applyOperator(token[0]);
            }
        } else if (isdigit(token[0]) || token[0] == '-') {
            int number = strToInt(token);
            if (number > 10 || number < 0) {
                throw std::invalid_argument("Number out of range: " + token);
            }
            this->_numbers.push(number);
        } else {
            throw std::invalid_argument("Invalid token: " + token);
        }
    }

    if (this->_numbers.size() != 1 || this->_operators.size() != 0) {
        throw std::invalid_argument("Invalid expression");
    }
    this->_isCalculated = true;
    _result = _numbers.top();
}

int RPN::getResult() const {
    if (!_isCalculated) {
        throw std::invalid_argument("Expression not calculated");
    }
    return _result;
}

void RPN::clearStacks() {
    while (!_numbers.empty()) {
        _numbers.pop();
    }
    while (!_operators.empty()) {
        _operators.pop();
    }
}