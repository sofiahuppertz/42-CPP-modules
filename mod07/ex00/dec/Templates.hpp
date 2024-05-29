#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>
#include "ANSIColors.hpp"

template <typename T> 
void swap( T &a, T &b) {

    T temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename T> 
T min( T a, T b ) {

    return (a < b) ? a : b;
}

template <typename T> 
T max( T a, T b ) {

    return (a > b ) ? a : b;
}

template <typename T>
void SortList(T arr[], int size)
{
    for (int i = 0; i < size -1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            T minValue = min(arr[i], arr[j]);
            if (minValue == arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
void printListInfo (T arr[], int size)
{
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "Size:" << ANSIColors::RESET << " " << ANSIColors::BRIGHT_GREEN << size << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN  << "Content:"  << ANSIColors::RESET << " ";
    for (int i = 0; i < size; i++)
    {
        std::cout << ANSIColors::BRIGHT_GREEN << arr[i] << " ";
    }
    std::cout << ANSIColors::RESET << std::endl;
    SortList(arr, size);
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "Minimum:" << ANSIColors::RESET << " " << ANSIColors::BRIGHT_GREEN << arr[0] <<  ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "Maximum:" << ANSIColors::RESET << " "<< ANSIColors::BRIGHT_GREEN << arr[size - 1] <<  ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "Sorted:" << ANSIColors::RESET << " ";
    for (int i = 0; i < size; i++)
    {
        std::cout << ANSIColors::BRIGHT_GREEN << arr[i] << " ";
    }
    std::cout << ANSIColors::RESET << std::endl;
}


#endif