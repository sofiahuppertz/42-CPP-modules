#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

class Intern {

    public: 
        Intern ( void );
        Intern ( Intern const &other );
        Intern &operator=( Intern const &other );
        ~Intern( void );
        AForm *makeForm( std::string formName, std::string target );
};

 
# endif