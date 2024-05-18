#include "dec/ScalarConverter.class.hpp"

// DOUBLE MAX: 1.7976931348623157E+308;
// DOUBLE MIN: 2.2250738585072014E-308;
// FLOAT MAX: 3.4028235E+38;
// FLOAT MIN: 1.17549435E-38;
// INT MAX: 2147483647;
// INT MIN: -2147483648;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

