#include "dec/Array.class.hpp"

int main( void ){

    Array<int>a; // Calls the default constructor
    try {
        std::cout << "Accessing a:" << std::endl;
        a[0] = 42;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<int>b(5);
    try {
        std::cout << "Accessing and printing b:" << std::endl;
        for (unsigned int i = 0; i < b.size(); i++) {
            b[i] = i;
        }
        std::cout << b[4] << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<char>c(3);
    try {
        std::cout << "Printing c:" << std::endl;
        for (unsigned int i = 0; i < c.size(); i++) {
            c[i] = 97 + i;
            std::cout << c[i] << ", ";
        }
        std::cout << c[3] << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<char>d(c);
    try {
        std::cout << "Printing d:" << std::endl;
        for (unsigned int i = 0; i < d.size(); i++) {
            std::cout << d[i] << ", ";
        }
        std::cout << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<char>e;
    try {
        std::cout << "Printing e:" << std::endl;
        e = d;
        for (unsigned int i = 0; i < e.size(); i++) {
            std::cout << e[i] << ", ";
        }
        std::cout << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}