#include "dec/Bureaucrat.class.hpp"

int main ( void )
{
    {
        std::cout << std::endl << "Test 1 " << std::endl;
        Bureaucrat Sofia("Sofia", 1);
        Form form1("Form1", 1, 1);
        try 
        {
            std::cout << Sofia << std::endl;
            std::cout << form1 << std::endl;
            Sofia.decrementGrade();
            Sofia.signForm(form1);
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
        std::cout << form1 << std::endl;
    }
    {
        try {
            std::cout << std::endl << "Test 2 " << std::endl;
            Bureaucrat Sofia("Sofia", 150);
            Form form1("Form1", 149, 1);
            std::cout << Sofia << std::endl;
            std::cout << form1 << std::endl;
            form1.beSigned(Sofia);
            std::cout << form1 << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
    }
    {
        try 
        {
            std::cout << std::endl << "Test 2 " << std::endl;
            Bureaucrat Sofia("Sofia", 150);
            Form form1("Form1", 149, 1);
            std::cout << Sofia << std::endl;
            std::cout << form1 << std::endl;
            Sofia.incrementGrade();
            form1.beSigned(Sofia);
            std::cout << form1 << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
    }
    std::cout << std::endl;
    return 0;
}