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


AForm *Intern::makeShrubberyCreationForm( std::string target )
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm( std::string target )
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm( std::string target )
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm( std::string formName, std::string target )
{
    std::string concreteFormName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*concreteForm[])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

    try {
        for (int i = 0; i < 3; i++) {
            if (concreteFormName[i] == formName) {
                std::cout << ANSIColors::BRIGHT_BACKGROUND_YELLOW << "Intern creates a " << formName << " form." << ANSIColors::RESET << std::endl;
                return concreteForm[i](target);
            }
        }
        throw FormNotFoundException();
    } 
    catch (std::exception &e) 
    {
        std::cout << ANSIColors::BACKGROUND_RED << "Exception caught:" << ANSIColors::RESET << ANSIColors::RED << " " << e.what() << ANSIColors::RESET << std::endl;
        return NULL;
    }
}

// FormNotFoundException 
const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form doesn't exist.";
}