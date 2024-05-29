#ifndef SCALARCONVERTER_CLASS_HPP
#define SCALARCONVERTER_CLASS_HPP


#include <climits>
#include <limits>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>


class ScalarConverter {


    public:

        static void convert ( std::string input );

        static void setConversions ( double Value, std::ostringstream (&outputs)[4], int is_inf );
        static void printConversions( std::ostringstream const (&outputs)[4]);

        static std::ostringstream convertChar ( double Value );
        static std::ostringstream convertInt ( double Value );
        static std::ostringstream convertFloat ( double Value, int is_inf );
        static std::ostringstream convertDouble ( double Value, int is_inf );

        static bool isChar ( std::string const &literal );
        static bool isInf ( std::string const &literal );
        static bool isOverflow ( float const &Value );
        static bool isOverflow ( double const &Value );

        static std::string removeTrailingF ( std::string literal );
        static double convertToDouble ( std::string literal );


        static const float max_float;
        static const double max_double;

    private:

        ScalarConverter ( void );
        ScalarConverter ( ScalarConverter const & other );
        ~ScalarConverter ( void );

        ScalarConverter & operator = ( ScalarConverter const & other );

};

# endif