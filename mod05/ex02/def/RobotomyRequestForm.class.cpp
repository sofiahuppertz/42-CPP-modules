#include "../dec/RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45) 
{
    std::cout << "Calling RobotomyRequestForm constructor." << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm(other) {
    std::cout << "Calling RobotomyRequestForm copy constructor." << std::endl;
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    (void)other;
    std::cout << "Calling RobotomyRequestForm assignment operator." << std::endl;
    return *this;
}


RobotomyRequestForm::~RobotomyRequestForm( void ) {
    std::cout << "Calling RobotomyRequestForm destructor." << std::endl;
    return ;
}


void RobotomyRequestForm::execute ( Bureaucrat const &executor ) const
{   
    std::cout << "RobotomyRequestForm execute() called." << std::endl;
    std::cout << "* SOME DRILLING NOISES *" << std::endl;
    std::cout << executor.getName() << " has been robotomized succesfully 50% of the time" << std::endl;
    return;
}

void RobotomyRequestForm::failure ( void )
{
    std::cout << "Robotomy failed. " << std::endl;
    return;
}