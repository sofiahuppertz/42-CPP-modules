#include "dec/iter.hpp"

int main( void )
{
    int intArray[] = {1, 2, 3};
    double doubleArray[] = {1.1, 2.2, 3.3};
    char charArray[] = {'a', 'b', 'c'};

    iter(intArray, 3, print);
    iter(doubleArray, 3, print);
    iter(charArray, 3, print);

    iter(intArray, 3, increment);
    iter(doubleArray, 3, increment);
    iter(charArray, 3, increment);

    iter(intArray, 3, print);
    iter(doubleArray, 3, print);
    iter(charArray, 3, print);

    return 0;

}