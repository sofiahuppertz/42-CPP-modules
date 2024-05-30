#ifndef ITER_H
#define ITER_H

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "ANSIColors.hpp"

template <typename T>
void iter(T array[], size_t size, void (*func)(T&))
{
    if (size == 0 || !func)
        return;

    for (size_t i = 0; i < size; i++)
        func(array[i]);
}

template <typename T>
void print(T &i)
{
    std::string colors[] = {ANSIColors::RED, ANSIColors::GREEN, ANSIColors::YELLOW, ANSIColors::BLUE, ANSIColors::MAGENTA, ANSIColors::CYAN};    
    std::cout << colors[rand() % 6] << i << ANSIColors::RESET; 
    std::cout << " ";   

}

template <typename T>
void replaceWithO(T &i)
{
    i = 'o';
}

template <typename T>
void square(T &i)
{
    i *= i;
}



#endif