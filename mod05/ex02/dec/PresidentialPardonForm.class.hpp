#ifndef PRESIDENTIALPARDONFORM_CLASS_H
#define PRESIDENTIALPARDONFORM_CLASS_H

#include "AForm.class.hpp"

class PresidentialPardonForm : public AForm {

    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        virtual ~PresidentialPardonForm( void );

        virtual void execute(Bureaucrat const &executor) const;  
        virtual void failure(void);
};


#endif