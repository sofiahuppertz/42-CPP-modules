#include "dec/Bureaucrat.class.hpp"

int main ( void )
{
    {
        try 
        {
            std::cout << std::endl << "Test 1 " << std::endl;
            Bureaucrat Sofia("Sofia", 1);
            std::cout << Sofia << std::endl;
            Sofia.incrementGrade();
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
    }
    {
        try {
            std::cout << std::endl << "Test 2 " << std::endl;
            Bureaucrat Sofia("Sofia", 151);
            std::cout << Sofia << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
    }
    {
        try 
        {
            std::cout << std::endl << "Test 3 " << std::endl;
            Bureaucrat Sofia("Sofia", 150);
            std::cout << Sofia << std::endl;
            Sofia.decrementGrade();
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
    }
    {
        try 
        {
            std::cout << std::endl << "Test 4 " << std::endl;
            Bureaucrat Sofia("Sofia", 10);
            std::cout << Sofia << std::endl;
            Sofia.incrementGrade();
            std::cout << Sofia << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
    }
    std::cout << std::endl;
    return 0;
}