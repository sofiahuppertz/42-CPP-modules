#ifndef SCALARCONVERTER_CLASS_HPP
#define SCALARCONVERTER_CLASS_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <string> 

class ScalarConverter {


    public:
        ScalarConverter ( void );
        ScalarConverter ( ScalarConverter const & other );
        ~ScalarConverter ( void );

        virtual ScalarConverter & operator = ( ScalarConverter const & other ) = 0;

        static void convert ( std::string input );

};

# endif