#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <stdexcept>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

class Span {

    public:
        Span( void );
        Span ( unsigned int N );
        Span ( const Span & other );
        ~Span ( void );

        Span &operator=( const Span &other );

        // Member funcs
        void addNumber ( int n );
        void addNumber ( std::vector<int>::iterator begin, std::vector<int>::iterator end );
        unsigned int shortestSpan( void ) const;
        unsigned int longestSpan( void ) const;

    private:
        unsigned int storageCapacity;
        std::vector<int> storage;
};

# endif
