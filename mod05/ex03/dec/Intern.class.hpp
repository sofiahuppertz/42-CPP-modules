#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include <exception>
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

class Intern {

    public: 
        Intern ( void );
        Intern ( Intern const &other );
        Intern &operator=( Intern const &other );
        ~Intern( void );
        static AForm *makeShrubberyCreationForm( std::string target );
        static AForm *makeRobotomyRequestForm( std::string target );
        static AForm *makePresidentialPardonForm( std::string target );

        AForm *makeForm( std::string formName, std::string target );

        class FormNotFoundException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

};

 
# endif