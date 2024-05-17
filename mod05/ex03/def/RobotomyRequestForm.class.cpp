#include "../dec/RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45) 
{
    std::cout << "Calling RobotomyRequestForm constructor." << std::endl;
    target = "default";
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 25, 5) {
    target = _target;
    std::cout << "Calling RobotomyRequestForm constructor." << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm(other) {
    target = other.target;
    std::cout << "Calling RobotomyRequestForm copy constructor." << std::endl;
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    target = other.target;
    std::cout << "Calling RobotomyRequestForm assignment operator." << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
    std::cout << "Calling RobotomyRequestForm destructor." << std::endl;
    return ;
}


void RobotomyRequestForm::execute ( Bureaucrat const &executor ) const
{   
    (void)executor;
    std::cout << "RobotomyRequestForm execute() called." << std::endl;
    std::cout << "* SOME DRILLING NOISES *" << std::endl;
    std::cout << target << " has been robotomized succesfully 50% of the time" << std::endl;
    return;
}

void RobotomyRequestForm::failure ( void )
{
    std::cout << "Robotomy failed. " << std::endl;
    return;
}