#include "../dec/PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5) {
    setTarget("default");
    std::cout << "Calling PresidentialPardonForm constructor." << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentialPardonForm", 25, 5) {
    setTarget(_target);
    std::cout << "Calling PresidentialPardonForm constructor." << std::endl;
    return ;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): AForm(other) {
    setTarget(other.getTarget());
    std::cout << "Calling PresidentialPardonForm copy constructor." << std::endl;
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    setTarget(other.getTarget());
    std::cout << "Calling PresidentialPardonForm assignment operator." << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
    std::cout << "Calling PresidentialPardonForm destructor." << std::endl;
    return ;
}

void PresidentialPardonForm::execute ( Bureaucrat const &executor ) const
{
    (void)executor;
    std::cout << "PresidentialPardonForm execute() called." << std::endl;
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
    return;
}

void PresidentialPardonForm::failure( void )
{
    return;
}