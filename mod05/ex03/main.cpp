#include "dec/Bureaucrat.class.hpp"
#include "dec/Intern.class.hpp"
#include "dec/ShrubberyCreationForm.class.hpp"
#include "dec/RobotomyRequestForm.class.hpp"
#include "dec/PresidentialPardonForm.class.hpp"

int main( void )
{
    {
        std::cout << std::endl << "Test 1" << std::endl;
        Intern i;
        AForm *form1 = i.makeForm("shrubbery creation", "Lisa");
        form1->beSigned(Bureaucrat("Bureaucrat", 1));
        form1->execute(Bureaucrat("Bureaucrat", 1));
        std::cout << *form1 << std::endl;
        delete form1;
    }
    {
        std::cout << std::endl << "Test 2" << std::endl;
        Intern i;
        AForm *form1 = i.makeForm("robotomy request", "Lisa");
        form1->beSigned(Bureaucrat("Bureaucrat", 1));
        form1->execute(Bureaucrat("Bureaucrat", 1));
        std::cout << *form1 << std::endl;
        delete form1;
    }
    {
        std::cout << std::endl << "Test 3" << std::endl;
        Intern i;
        AForm *form1 = i.makeForm("presidential pardon", "Lisa");
        form1->beSigned(Bureaucrat("Bureaucrat", 1));
        form1->execute(Bureaucrat("Bureaucrat", 1));
        std::cout << *form1 << std::endl;
        delete form1;
    }
}