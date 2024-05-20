#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Element Not Found.";
        };
};

template <typename T>
typename T::iterator easyfind( T &container, int value);

#include "../def/easyfind.tpp"


# endif
