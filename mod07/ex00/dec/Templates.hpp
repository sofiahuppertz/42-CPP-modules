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
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "\tSize:" << ANSIColors::RESET << "\t" << ANSIColors::BRIGHT_CYAN << size << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN  << "\tContent:"  << ANSIColors::RESET << " ";
    for (int i = 0; i < size; i++)
    {
        std::cout << ANSIColors::BRIGHT_CYAN << arr[i] << ", ";
    }
    std::cout << ANSIColors::RESET << std::endl;
    SortList(arr, size);
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "\tMinimum:" << ANSIColors::RESET << " " << ANSIColors::BRIGHT_CYAN << arr[0] <<  ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "\tMaximum:" << ANSIColors::RESET << " "<< ANSIColors::BRIGHT_CYAN << arr[size - 1] <<  ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN << "\tSorted:" << ANSIColors::RESET << "\t";
    for (int i = 0; i < size; i++)
    {
        std::cout << ANSIColors::BRIGHT_CYAN << arr[i] << ", ";
    }
    std::cout << ANSIColors::RESET << std::endl;
}


#endif