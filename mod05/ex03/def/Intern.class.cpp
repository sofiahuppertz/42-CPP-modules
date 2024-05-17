#include "../dec/Intern.class.hpp"

Intern::Intern( void ) {
    return;
}

Intern::~Intern( void ) {
    return ;
}

Intern::Intern( Intern const &other ) {
    *this = other;
    return ;
}

Intern &Intern::operator=( Intern const &other ) {
    (void)other;
    return *this;
}


static AForm *makeShrubberyCreationForm( std::string target )
{
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomyRequestForm( std::string target )
{
    return new RobotomyRequestForm(target);
}

static AForm *makePresidentialPardonForm( std::string target )
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm( std::string formName, std::string target )
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*formCreators[])(std::string) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
}