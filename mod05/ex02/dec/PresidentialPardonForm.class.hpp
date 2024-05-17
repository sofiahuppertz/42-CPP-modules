#ifndef PRESIDENTIALPARDONFORM_CLASS_H
#define PRESIDENTIALPARDONFORM_CLASS_H

#include "AForm.class.hpp"

class PresidentialPardonForm : public AForm {

    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm(std::string _target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        virtual ~PresidentialPardonForm( void );
        virtual void local_execute(Bureaucrat const &executor) const;  
        virtual void local_failure(void) const;
};


#endif