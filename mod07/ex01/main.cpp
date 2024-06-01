#include "dec/iter.hpp"

int main( void )
{

    /* To later generate random colors on print function... */
    srand(static_cast<unsigned int>(time(0)));


    std::string str = "Hello, World!";
    char charArr[str.length() + 1];
    std::copy(str.begin(), str.end(), charArr);

    std::cout << ANSIColors::BACKGROUND_BLUE << "We have an array of chars : " << ANSIColors::RESET << std::endl;
    std::cout << "\t";
    iter(charArr, str.length(), print);
    std::cout << std::endl << std::endl;

    std::cout << ANSIColors::BACKGROUND_BLUE << "After calling iter() with replaceWithO(): " << ANSIColors::RESET << std::endl;
    iter(charArr, str.length(), replaceWithO);
    std::cout << "\t";
    iter(charArr, str.length(), print);
    std::cout << std::endl << std::endl;

    double doubleArr[] = {0.5, 5, 16.16};
    int size = sizeof(doubleArr) / sizeof(doubleArr[0]);
    std::cout << ANSIColors::BACKGROUND_BLUE << "We have an array of doubles : " << ANSIColors::RESET << std::endl;
    std::cout << "\t";
    iter(doubleArr, size, print);
    std::cout << std::endl << std::endl;

    std::cout << ANSIColors::BACKGROUND_BLUE << "After calling iter() with square(): " << ANSIColors::RESET << std::endl;
    iter(doubleArr, size, square);
    std::cout << "\t";
    iter(doubleArr, size, print);
    std::cout << std::endl << std::endl;

    return 0;

}