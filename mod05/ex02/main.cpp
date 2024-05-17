#include "dec/Bureaucrat.class.hpp"
#include "dec/ShrubberyCreationForm.class.hpp"
#include "dec/RobotomyRequestForm.class.hpp"
#include "dec/PresidentialPardonForm.class.hpp"

int main( void )
{
    {
        std::cout << std::endl << "Test 1" << std::endl;
        Bureaucrat b("Sofia", 146);
        AForm *form1 = new ShrubberyCreationForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;
    }
    {
        std::cout << std::endl << "Test 2" << std::endl;
        Bureaucrat b("Sofia", 130);
        AForm *form1 = new ShrubberyCreationForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;   
    }
    {
        std::cout << std::endl << "Test 3" << std::endl;
        Bureaucrat b("Sofia", 1);
        AForm *form1 = new ShrubberyCreationForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        b.signAForm(*form1);
        std::cout << *form1 << std::endl;
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;   
    }
    std::cout << std::endl;
    {
        std::cout << std::endl << "Test 4" << std::endl;
        Bureaucrat b("Sofia", 40);
        AForm *form1 = new RobotomyRequestForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;
    }
    {
        std::cout << std::endl << "Test 5" << std::endl;
        Bureaucrat b("Sofia", 130);
        AForm *form1 = new RobotomyRequestForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;   
    }
    {
        std::cout << std::endl << "Test 6" << std::endl;
        Bureaucrat b("Sofia", 1);
        AForm *form1 = new RobotomyRequestForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->beSigned(b);
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;   
    }
    std::cout << std::endl;
    {
        std::cout << std::endl << "Test 7" << std::endl;
        Bureaucrat b("Sofia", 146);
        AForm *form1 = new PresidentialPardonForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;
    }
    {
        std::cout << std::endl << "Test 8" << std::endl;
        Bureaucrat b("Sofia", 10);
        AForm *form1 = new PresidentialPardonForm();
        b.signAForm(*form1);
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;   
    }
    {
        std::cout << std::endl << "Test 9" << std::endl;
        Bureaucrat b("Sofia", 1);
        AForm *form1 = new PresidentialPardonForm();
        std::cout << b << std::endl;
        std::cout << *form1 << std::endl;
        form1->beSigned(b);
        form1->execute(b);
        std::cout << *form1 << std::endl;
        delete form1;   
    }
    {
        std::cout << std::endl << "Test 10" << std::endl;
        Bureaucrat b("Sofia", 1);
        AForm *form1 = new PresidentialPardonForm();
        b.signAForm(*form1);
        b.executeForm(*form1);
        delete form1;   
    }
    {
        std::cout << std::endl << "Test 11" << std::endl;
        Bureaucrat b("Sofia", 100);
        AForm *form1 = new PresidentialPardonForm();
        b.executeForm(*form1);
        delete form1;   
    }
    {
        std::cout << std::endl << "Test 11" << std::endl;
        Bureaucrat b("Sofia", 1);
        AForm *form1 = new PresidentialPardonForm();
        b.executeForm(*form1);
        delete form1;   
    }
    std::cout << std::endl;
}