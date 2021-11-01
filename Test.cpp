#include "cute/cute.h"
#include "cute/ide_listener.h"
#include "cute/xml_listener.h"
#include "cute/cute_runner.h"
#include "pocketcalculator.h"

#include <sstream>

void testSingleDigitResult() {
	std::istringstream input{"1+1"};
	std::ostringstream output{};
	pocketcalculator(input, output);
	ASSERT_EQUAL(      " - \n"
		               "  |\n"
		               " - \n"
		               "|  \n"
		               " - \n", output.str());
}

void testMultipleDigitResult() {
	std::istringstream input{"10*10"};
	std::ostringstream output{};
	pocketcalculator(input, output);
	ASSERT_EQUAL(      "    -  - \n"
		               " | | || |\n"
		               "         \n"
		               " | | || |\n"
		               "    -  - \n", output.str());
}

void testMinusResult() {
	std::istringstream input{"10*-10"};
	std::ostringstream output{};
	pocketcalculator(input, output);
	ASSERT_EQUAL(      "       -  - \n"
		               "    | | || |\n"
		               " -          \n"
		               "    | | || |\n"
		               "       -  - \n", output.str());
}

void testDivisionByZero() {
	std::istringstream input{"1/0"};
	std::ostringstream output{};
	pocketcalculator(input, output);
	ASSERT_EQUAL(      " - \n"
		               "|  \n"
		               " -  -  -  -  - \n"
		               "|  |  |  | ||\n"
		               " -        -\n", output.str());
}

void testWrongInput() {
	std::istringstream input{"1+"};
	std::ostringstream output{};
	pocketcalculator(input, output);
	ASSERT_EQUAL(	   " - \n"
			           "|  \n"
			           " -  -  -  -  - \n"
			           "|  |  |  | ||\n"
			           " -        -\n", output.str());
}

void testNumberWiderThan8Digits() {
	std::istringstream input{"10000*10000"};
	std::ostringstream output{};
	pocketcalculator(input, output);
	ASSERT_EQUAL(      " - \n"
				       "|  \n"
				       " -  -  -  -  - \n"
				       "|  |  |  | ||\n"
				       " -        -\n", output.str());
}

bool runAllTests(int argc, char const *argv[]) {
  cute::suite s { };
  //TODO Register tests
  s.push_back(CUTE(testSingleDigitResult));
  s.push_back(CUTE(testMultipleDigitResult));
  s.push_back(CUTE(testMinusResult));
  s.push_back(CUTE(testDivisionByZero));
  s.push_back(CUTE(testWrongInput));
  s.push_back(CUTE(testNumberWiderThan8Digits));
  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
  auto runner = cute::makeRunner(lis, argc, argv);
  bool success = runner(s, "AllTests");
  return success;
}

//int main(int argc, char const *argv[]) {
//  return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
//}
