#include "../dec/ScalarConverter.class.hpp"


const float ScalarConverter::max_float = std::numeric_limits<float>::max();
const double ScalarConverter::max_double = std::numeric_limits<double>::max();


bool ScalarConverter::isOverflow( float const &Value ) {
   return (Value > ScalarConverter::max_float || Value < -ScalarConverter::max_float);
}

bool ScalarConverter::isOverflow( double const &Value ){
    return (Value > ScalarConverter::max_double || Value < -ScalarConverter::max_double);
}

bool ScalarConverter::isChar( std::string const &literal ) {

    if (literal.length() == 1 && !isdigit(literal[0]))
        return true;
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return true;
    return false;
}

bool ScalarConverter::isInf( std::string const &literal ) {

    return (literal == "inf" || literal == "-inf" || literal == "+inf" ||literal == "inff" || literal == "-inff" || literal == "+inff");
}

std::ostringstream ScalarConverter::convertChar( double Value )
{
    std::ostringstream os;

    if (Value > CHAR_MAX || Value < CHAR_MIN || (Value != Value))
        os <<  "impossible";
    else if (isprint(static_cast<char>(Value)))
        os << "'" << static_cast<char>(Value) << "'";
    else
        os << "Non displayable" ;
    return os;
}

std::ostringstream ScalarConverter::convertInt( double Value )
{
    std::ostringstream os;

    if (Value > INT_MAX || Value < INT_MIN || (Value != Value))
        os << "impossible";
    else
        os << static_cast<int>(Value);
    return os;
}


std::ostringstream ScalarConverter::convertFloat( double Value, int is_inf )
{
    std::ostringstream os;

    if (is_inf)
        os << (Value > 0 ? "inff" : "-inff");
    else if (ScalarConverter::isOverflow(static_cast<float>(Value)))
        os << "impossible";
    else if (Value == std::floor(Value))
        os << std::fixed << std::setprecision(1) << static_cast<float>(Value) << "f";
    else
        os << static_cast<float>(Value) << "f";
    return os;
}

std::ostringstream ScalarConverter::convertDouble( double Value, int is_inf)
{
    std::ostringstream os;

    if (!is_inf && ScalarConverter::isOverflow(Value))
        os << "impossible";
    else if (Value == std::floor(Value))
        os << std::fixed << std::setprecision(1) << Value;
    else
        os << Value;
    return os;
}


std::string ScalarConverter::removeTrailingF( std::string literal ) {

    if (literal == "inf" || literal == "-inf")
        return literal;
    if (literal[literal.length() - 1] == 'f' || literal[literal.length() - 1] == 'F')
        return literal.substr(0, literal.length() - 1);
    return literal;
}

double ScalarConverter::convertToDouble( std::string literal ) {

    std::istringstream i(literal);
    double Value;

    if (ScalarConverter::isChar(literal))
    {
        if (literal.length() == 3)
            Value = static_cast<double>(literal[1]);
        else
            Value = static_cast<double>(literal[0]);
    }
    else
        i >> Value;
    if (Value == 0 && literal.length() != 1 && literal != "-0")
        throw std::exception();

    return Value;
}

void ScalarConverter::printConversions(std::ostringstream const (&outputs)[4]) 
{
    std::string types[4] = {"char", "int", "float", "double"};
    std::string colors[4] = {"\033[36m", "\033[32m", "\033[33m", "\033[35m"};
    std::string reset = "\033[0m";
    std::string brightWhite = "\033[97m";

    for (int i = 0; i < 4; i++)
    {
        std::cout << colors[i] << types[i] << reset << ": " 
                  << brightWhite << outputs[i].str() << reset << std::endl;
    }
}


void ScalarConverter::setConversions( double Value, std::ostringstream (&outputs)[4], int is_inf)
{
    outputs[0] = convertChar(Value);
    outputs[1] = convertInt(Value);
    outputs[2] = convertFloat(Value, is_inf);
    outputs[3] = convertDouble(Value, is_inf);
}

void ScalarConverter::convert( std::string literal ) 
{
    std::ostringstream outputs[4];
    int is_inf = 0; 
    try 
    {

        if (literal.empty())
            throw std::exception();
        
        if (isInf(literal))
            is_inf = 1;

        if (!isChar(literal))
            literal = ScalarConverter::removeTrailingF(literal);

        double Value = ScalarConverter::convertToDouble(literal);

        setConversions(Value, outputs, is_inf);
    }
    catch (std::exception & e) 
    {
        for (int i = 0; i < 4; i++)
            outputs[i] << "impossible";
    }
    printConversions(outputs);
    return;
}


// Private Constructors and destructors

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

ScalarConverter & ScalarConverter::operator=( ScalarConverter const & other ) {
    static_cast<void>(other);
    return *this;
}
