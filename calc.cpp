#include "calc.h"
#include <stdexcept>

int calculateResult(char op, int lhs, int rhs) {
	switch (op) {
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '*':
		return lhs * rhs;
	case '/':
		if (rhs) {
			return lhs / rhs;
		}
		throw std::invalid_argument{"Division by Zero"};
	default:
		throw std::invalid_argument{"Insufficient arguments"};
	}
}

int calc(int lhs, int rhs, char op) {
	try {
		return calculateResult(op, lhs, rhs);
	} catch(std::invalid_argument const & e) {
		throw e;
	}
}

int calc(std::istream& in) {
	int lhs{};
	int rhs{};
	char op{};

	if(in >> lhs >> op >> rhs) {
		try {
			return calculateResult(op, lhs, rhs);
		} catch(std::invalid_argument const & e) {
			throw e;
		}
	}
	throw std::invalid_argument{"Insufficient arguments"};
}
