#ifndef SHRUBBERYCREATIONFORM_CLASS_H
# define SHRUBBERYCREATIONFORM_CLASS_H

#include "AForm.class.hpp"

class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        virtual ~ShrubberyCreationForm( void );
        virtual void execute(Bureaucrat const &executor) const;
        virtual void failure( void );
};

# endif