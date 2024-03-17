#include "dec/Fixed.class.hpp"

int main ( void )
{
    // Default constructor called.
    Fixed a;

    // Copy constructor called.
    Fixed b( a );

    // Default constructor called.
    Fixed c;

    // Copy assignment operator called.
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}