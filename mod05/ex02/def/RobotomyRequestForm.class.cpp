#include "../dec/RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45)
{
    setTarget("default");
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 72, 45)
{
    setTarget(_target);
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm(other) {

    setTarget(other.getTarget());
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {

    setTarget(other.getTarget());
    return *this;
}


RobotomyRequestForm::~RobotomyRequestForm( void ) {
    return ;
}


void RobotomyRequestForm::local_execute ( Bureaucrat const &executor ) const
{
    (void)executor;
    std::cout << "\t" << ANSIColors::MAGENTA << "⚙️  [RobotomyRequestForm]: Initiating robotomy procedure..." << std::endl;
    std::cout << "\t" << "🔊 [RobotomyRequestForm]: Imagine the sound of a jackhammer breaking into concrete... 🛠️" << std::endl;
    std::cout << "\t" << "🤖 [RobotomyRequestForm]: Target " << getTarget() << " is undergoing robotomization..." << ANSIColors::RESET << std::endl;
    std::cout << "\t" << ANSIColors::BRIGHT_BACKGROUND_GREEN <<  "🔄 [RobotomyRequestForm]: Robotomization complete! Success rate: 50% - Flip a coin! 🤞" <<  ANSIColors::RESET << std::endl;

    return;
}

void RobotomyRequestForm::local_failure ( void ) const
{
    std::cout << "Robotomy failed. " << std::endl;
    return;
}