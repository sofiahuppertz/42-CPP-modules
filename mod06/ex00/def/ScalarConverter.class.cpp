#include "../dec/ScalarConverter.class.hpp"


const float ScalarConverter::max_float = std::numeric_limits<float>::max();
const double ScalarConverter::max_double = std::numeric_limits<double>::max();
const double ScalarConverter::positive_infinity = std::numeric_limits<double>::infinity();
const double ScalarConverter::negative_infinity = -std::numeric_limits<double>::infinity();

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

bool ScalarConverter::isNumber(std::string const &literal)
{
    int dot;
    int i;

    i  = 0;
    dot = 0;
    if (literal[i] == '+' or literal[i] == '-')
        i++;
    for(;i < int(literal.length()); i++)
    {
        if (std::isdigit(literal[i]) || (literal[i] == 'E' && literal[i + 1] == '+' && i++) || (literal[i] == '.' && dot == 0))
        {
            dot = literal[i] == '.' ? 1 : dot;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isInf( std::string const &literal ) {

    return (literal == "inf" || literal == "-inf" || literal == "+inf" ||literal == "inff" || literal == "-inff" || literal == "+inff");
}

void ScalarConverter::convertChar( double Value, std::ostringstream &os )
{
    if (Value > CHAR_MAX || Value < CHAR_MIN || (Value != Value))
        os <<  "impossible";
    else if (isprint(static_cast<char>(Value)))
        os << "'" << static_cast<char>(Value) << "'";
    else
        os << "Non displayable" ;

}

void  ScalarConverter::convertInt( double Value, std::ostringstream &os )
{
    if (Value > INT_MAX || Value < INT_MIN || (Value != Value))
        os << "impossible";
    else
        os << static_cast<int>(Value);

}


void ScalarConverter::convertFloat( double Value, std::ostringstream &os, int is_inf )
{
    if (is_inf)
        os << (Value > 0 ? "inff" : "-inff");
    else if (ScalarConverter::isOverflow(static_cast<float>(Value)))
        os << "impossible";
    else if (Value == std::floor(Value))
        os << std::fixed << std::setprecision(1) << static_cast<float>(Value) << "f";
    else
        os << static_cast<float>(Value) << "f";
}

void ScalarConverter::convertDouble( double Value, std::ostringstream &os, int is_inf)
{
    if (!is_inf && ScalarConverter::isOverflow(Value))
        os << "impossible";
    else if (Value == std::floor(Value))
        os << std::fixed << std::setprecision(1) << Value;
    else
        os << Value;

}


std::string ScalarConverter::removeTrailingF( std::string literal ) {

    if (literal == "inf" || literal == "-inf")
        return literal;
    if (literal[literal.length() - 1] == 'f' || literal[literal.length() - 1] == 'F')
        return literal.substr(0, literal.length() - 1);
    return literal;
}



double ScalarConverter::convertToDouble( std::string literal, int is_inf ) {

    std::istringstream i(literal);
    double Value;

    if (ScalarConverter::isChar(literal))
    {
        if (literal.length() == 3)
            Value = static_cast<double>(literal[1]);
        else
            Value = static_cast<double>(literal[0]);
    }
    else if (is_inf)
    {
        if (literal[0] == '-')
            Value = ScalarConverter::negative_infinity;
        else
            Value = ScalarConverter::positive_infinity;
    }
    else
        i >> Value;
    if (!is_inf && Value == 0 && literal.length() != 1 && literal != "-0")
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
    ScalarConverter::convertChar(Value, outputs[0]);
    ScalarConverter::convertInt(Value, outputs[1]);
    ScalarConverter::convertFloat(Value, outputs[2], is_inf);
    ScalarConverter::convertDouble(Value, outputs[3], is_inf);
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
        {
            literal = ScalarConverter::removeTrailingF(literal);
            if (!is_inf && !isNumber(literal))
                throw std::exception();
        }

        double Value = ScalarConverter::convertToDouble(literal, is_inf);
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
