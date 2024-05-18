#include "../dec/ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter ( void ) {
    return ;
}

ScalarConverter::ScalarConverter ( ScalarConverter const & other ) {
    *this = other;
    return ;
}

ScalarConverter::~ScalarConverter ( void ) {
    return ;
}

static void printAllImpossible( void ) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}


static void printCharConversions( void *literal)
{
    char c = *(static_cast<char *>(literal));
    std::cout << "char: ";
    try {
        if (isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    try {
        std::cout <<  static_cast<int>(c) << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "impossible" << std::endl;
    
    }
    std::cout << "float: ";
    try {
        std::cout << static_cast<float>(c) << "f" << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "double: ";
    try {
        std::cout << static_cast<double>(c) << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "impossible" << std::endl;
    }
    return;
}


void printNumericalConversions( double Value)
{
    std::cout << "char: ";
    if (Value > CHAR_MAX || Value < CHAR_MIN || isnan(Value))
        std::cout << "impossible" << std::endl;
    else if (isprint(static_cast<char>(Value)))
        std::cout << "'" << static_cast<char>(Value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (Value > INT_MAX || Value < INT_MIN || isnan(Value))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(Value) << std::endl;

    std::cout << "float: ";
    //if (isnan(Value))
    //    std::cout << "nanf" << std::endl;
    if (isinf(Value))
        std::cout << (Value > 0 ? "inff" : "-inff") << std::endl;
    else 
    {
        float fValue = static_cast<float>(Value);
        if (fValue == std::floor(fValue))
            std::cout << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;
        else
            std::cout << std::defaultfloat << fValue << "f" << std::endl;
    }

    std::cout << "double: ";
    if (Value == std::floor(Value))
        std::cout << std::fixed << std::setprecision(1) << Value << std::endl;
    else
        std::cout << std::defaultfloat << Value << std::endl;

}


void ScalarConverter::convert( std::string literal ) {

    if (literal.empty()) {
        printAllImpossible();
        return;
    }
    if ((literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')){ 
        
        char Value = literal[1];
        printCharConversions(&Value);
        return;
    }
    if (literal.length() == 1 && !isdigit(literal[0])) {
        char Value = literal[0];
        printCharConversions(&Value);
        return;
    }
    try {
        std::size_t pos = 0;
        double Value = std::stod(literal, &pos);
        if (pos != literal.length())
            throw std::exception();
        printNumericalConversions(Value);
        return;
    }
    catch (std::exception & e) {}
    try {
        std::size_t pos = 0;

        float Value = std::stof(literal, &pos);
        if (pos != literal.length() && !(pos == literal.length() - 1 && (literal[pos] == 'f' || literal[pos] == 'F')))
            throw std::exception();
        double dValue = static_cast<double>(Value);
        printNumericalConversions(dValue);
        return;
    }
    catch (std::exception & e) {}

    // If nothing works...
    printAllImpossible();

    return;
}