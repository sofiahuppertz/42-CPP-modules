#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <exception>
#include <algorithm>
#include <typeinfo>
#include <cassert>
#include "../dec/ANSIColors.hpp"


template <typename T>
typename T::iterator easyfind( T &container, int value);

#include "../def/easyfind.tpp"


# endif
