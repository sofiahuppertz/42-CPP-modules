#ifndef ROBOTOMYREQUESTFORM_CLASS_H
#define ROBOTOMYREQUESTFORM_CLASS_H

#include "AForm.class.hpp"

class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        virtual ~RobotomyRequestForm( void );
        virtual void execute(Bureaucrat const &executor) const;  
        virtual void local_failure(void);
};


#endif