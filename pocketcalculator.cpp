#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"

#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

void pocketcalculator(std::istream &in, std::ostream &out) {
	
	int result;

	try {
		result = calc(in);
	} catch(std::invalid_argument const & e) {
		printLargeError(out);
		return;
	} catch(...) {
		printLargeError(out);
		return;
	}

	if(result > 99999999 || result < -9999999) {
		printLargeError(out);
	} else if(result >= 10) {
		printLargeNumber(result, out);
	} else if(result < 0) {
		printLargeNumber(result, out);
	} else {
		printLargeDigit(result, out);
	}
}

int main(int argc, char **argv) {
	std::string operation {};
	while(std::getline(std::cin, operation)) {
		std::istringstream input(operation);
		pocketcalculator(input, std::cout);
	}
}


