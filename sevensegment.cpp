#include "sevensegment.h"
#include <ostream>
#include <array>
#include <string>
#include <sstream>

std::array<std::string, 5> const numberOne = {"   ", " | ", "   ", " | ", "   "};
std::array<std::string, 5> const numberTwo = {" - ", "  |", " - ", "|  ", " - "};
std::array<std::string, 5> const numberThree = {" - ", "  |", " - ", "  |", " - "};
std::array<std::string, 5> const numberFour = {"   ", "| |", " - ", "  |", "   "};
std::array<std::string, 5> const numberFive = {" - ", "|  ", " - ", "  |", " - "};
std::array<std::string, 5> const numberSix = {" - ", "|  ", " - ", "| |", " - "};
std::array<std::string, 5> const numberSeven = {" - ", "  |", "   ", "  |", "   "};
std::array<std::string, 5> const numberEight = {" - ", "| |", " - ", "| |", " - "};
std::array<std::string, 5> const numberNine = {" - ", "| |", " - ", "  |", " - "};
std::array<std::string, 5> const numberZero = {" - ", "| |", "   ", "| |", " - "};
std::array<std::string, 5> const error = {" - ", "|  ", " -  -  -  -  - ", "|  |  |  | ||", " -        -"};
std::array<std::string, 5> const minus = {"   ", "   ", " - ", "   ", "   "};

std::array<std::array<std::string, 5>, 10> const digits = {numberZero, numberOne, numberTwo, numberThree, numberFour, numberFive, numberSix, numberSeven, numberEight, numberNine};

void printLargeDigit(int i, std::ostream &out) {
	std::array<std::string, 5> const digit = digits[i];
	out << digit[0] << "\n" << digit[1] << "\n" << digit[2] << "\n" << digit[3] << "\n" << digit[4] << std::endl;
}
void printLargeNumber(int i, std::ostream &out) {
	std::ostringstream os;
	os << i;
	std::string number = os.str();
	int length = number.size();

	for(int y = 0; y <= 4; y++) {
		for(int z = 0; z < length; z++) {
			if(number[z] == '-') {
				out << minus[y];
			} else {
				int digit = number[z] - '0';
				out << digits[digit][y];
			}
		}
		out << "\n";
	}

}
void printLargeError(std::ostream &out) {
	out << error[0] << "\n" << error [1] << "\n" << error [2] << "\n" << error[3] << "\n" << error[4] << std::endl;
}

