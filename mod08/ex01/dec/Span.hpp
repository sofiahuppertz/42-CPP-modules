#ifndef SPAN_H
#define SPAN_H

#include "ANSIColors.hpp"
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

class Span {

    public:
        Span ( unsigned int N );
        Span ( const Span & other );
        ~Span ( void );

        Span &operator=( const Span &other );

        // Member funcs
        void addNumber ( int n );
        void addNumber ( std::vector<int>::iterator begin, std::vector<int>::iterator end );
        unsigned int shortestSpan( void ) const;
        unsigned int longestSpan( void ) const;

        // Getters
        unsigned int getCapacity( void ) const;
        unsigned int getSize( void ) const;

        void print( unsigned int last_index ) const;

    private:
        Span( void );

        std::vector<int> storage;
};

# endif
