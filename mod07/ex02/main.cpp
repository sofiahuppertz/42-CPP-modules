#include "dec/Array.class.hpp"

int main( void ){

    Array<int>a; // Calls the default constructor
    try {
        a[0] = 42;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<int>b(5);
    try {
        for (unsigned int i = 0; i < b.size(); i++) {
            b[i] = i;
        }
        std::cout << b[4] << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<char>c(3);
    try {
        for (unsigned int i = 0; i < c.size(); i++) {
            c[i] = 97 + i;
            std::cout << c[i] << std::endl;
        }
        std::cout << c[3] << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}