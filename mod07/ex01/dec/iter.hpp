#ifndef ITER_H
#define ITER_H

#include <cstddef>
#include <iostream>

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
    std::cout << i << std::endl;
}

template <typename T>
void increment(T &i)
{
    i++;
}



#endif