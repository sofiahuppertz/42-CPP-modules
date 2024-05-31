#include    "dec/Array.hpp"
#include    <cstdlib>
#include    <ctime>
#include    <string>
#include    <cassert>


int main( void )
{

    srand(std::time(0));
    std::cout << ANSIColors::BACKGROUND_GREEN << "We Have an Integers Array: " << ANSIColors::RESET << std::endl;
   
    Array <int>intArr(static_cast<unsigned int>(5));
    for (int i = 0; i < 5; i++)
        intArr[i] = rand() % 100;
    intArr.printArray();
    std::cout << std::endl;

    std::cout << ANSIColors::BACKGROUND_BLUE << "We Have a Char Array: " << ANSIColors::RESET << std::endl;
    Array <char>charArr(static_cast<unsigned int>(5));
    for (int i = 0; i < 5; i++)
        charArr[i] = static_cast<char>(rand() % 26 + 65);
    charArr.printArray();
    std::cout << std::endl;

    std::cout << ANSIColors::BACKGROUND_CYAN << "We can copy an array: " << ANSIColors::RESET << std::endl;
    Array <char>charArr2;
    charArr2 = charArr;
    charArr2.printArray();
    std::cout << std::endl;

    assert(charArr.getArray() != charArr2.getArray());
    std::cout << ANSIColors::BACKGROUND_MAGENTA << "\t✨ Asserted: deep copy of charArr -> charArr2 ✨" << ANSIColors::RESET << std::endl << std::endl;

    std::cout << ANSIColors::BACKGROUND_YELLOW << "Elements can be accessed through the subscript operator: " << ANSIColors::RESET << std::endl;
    std::cout << "\tintArr[2]: " << intArr[2] << std::endl;
    std::cout << std::endl;

    std::cout << ANSIColors::BACKGROUND_GREEN << "And if we try to access an index that is out of bounds, an exception is thrown: " << ANSIColors::RESET << std::endl;
    try {
        std::cout << "\tintArr[5]: " << intArr[5] << std::endl;
    } catch (std::exception & e) {
        std::cout << ANSIColors::BACKGROUND_RED << "Exception caught:" << ANSIColors::RESET << ANSIColors::RED << " " << e.what() << ANSIColors::RESET << std::endl;
    }
    std::cout << std::endl;


    return 0;
}