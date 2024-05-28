#include "dec/Bureaucrat.class.hpp"

int main ( void )
{
    {
        std::cout << std::endl << " This example will show how form signing is done. " << std::endl;
        Bureaucrat SirPapperPusher3("Sir PapperPusher the 3rd", 3);
        Form form1("Ninja Survey", 13, 4);
        try 
        {
            std::cout << SirPapperPusher3 << std::endl;
            std::cout << form1 << std::endl;
            SirPapperPusher3.decrementGrade(1);
            SirPapperPusher3.signForm(form1);
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
            Sofia.incrementGrade(1);
            form1.beSigned(Sofia);
            std::cout << form1 << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        };
    }
    {
        std::cout << std::endl << "Test 3 " << std::endl;
        Bureaucrat Sofia("Sofia", 150);
        Form form1("Form1", 149, 1);
        Sofia.signForm(form1);
        Sofia.incrementGrade(1);
        Sofia.signForm(form1);
    }
        {
        std::cout << std::endl << "Test 4 " << std::endl;
        Bureaucrat Sofia("Sofia", 130);
        Form form1("Form1", 140, 1);
        Sofia.signForm(form1);
        Sofia.incrementGrade(1);
        Sofia.signForm(form1);
    }
    std::cout << std::endl;
    return 0;
}