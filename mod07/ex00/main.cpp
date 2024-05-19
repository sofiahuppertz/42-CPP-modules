#include "dec/Templates.hpp"
#include <iostream>

int main (void)
{
    int int_a = 10, int_b = 20;
    double double_a = 10.5, double_b = 20.5;
    float float_a = 10.5, float_b = 10.55;
    char char_a = 'A', char_b = 'B';

    std::cout << "We will call the same function for different types thanks to templates " << std::endl << std::endl;
    std::cout << "int_a = " << int_a << ", int_b = " << int_b << std::endl;
    std::cout << "min(int_a, int_b) = " << min(int_a, int_b) << std::endl;
    std::cout << "max(int_a, int_b) = " << max(int_a, int_b) << std::endl;
    swap(int_a, int_b);
    std::cout << "After swap: int_a = " << int_a << ", int_b = " << int_b << std::endl << std::endl;

    std::cout << "double_a = " << double_a << ", double_b = " << double_b << std::endl;
    std::cout << "min(double_a, double_b) = " << min(double_a, double_b) << std::endl;
    std::cout << "max(double_a, double_b) = " << max(double_a, double_b) << std::endl;
    swap(double_a, double_b);
    std::cout << "After swap: double_a = " << double_a << ", double_b = " << double_b << std::endl  << std::endl;

    std::cout << "float_a = " << float_a << ", float_b = " << float_b << std::endl;
    std::cout << "min(float_a, float_b) = " << min(float_a, float_b) << std::endl;
    std::cout << "max(float_a, float_b) = " << max(float_a, float_b) << std::endl;
    swap(float_a, float_b);
    std::cout << "After swap: float_a = " << float_a << ", float_b = " << float_b << std::endl << std::endl;

    std::cout << "char_a = " << char_a << ", char_b = " << char_b << std::endl;
    std::cout << "min(char_a, char_b) = " << min(char_a, char_b) << std::endl;
    std::cout << "max(char_a, char_b) = " << max(char_a, char_b) << std::endl;
    swap(char_a, char_b);
    std::cout << "After swap: char_a = " << char_a << ", char_b = " << char_b << std::endl << std::endl;

}
