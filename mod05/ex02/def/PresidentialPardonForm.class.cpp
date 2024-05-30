#include "../dec/PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5) {
    setTarget("default");
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentialPardonForm", 25, 5) {
    setTarget(_target);
    return ;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): AForm(other) {
    setTarget(other.getTarget());
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    setTarget(other.getTarget());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
    return ;
}

void PresidentialPardonForm::local_execute (Bureaucrat const &executor) const
{
    (void)executor;
    std::cout << ANSIColors::CYAN
            << "\t"
              << "🚀 [Presidential Pardon]: Zaphod Beeblebrox, in all his intergalactic swagger, announces:"
              << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::BRIGHT_BACKGROUND_CYAN
            << "\t"
              << ANSIColors::WHITE
              << "✨ " << getTarget() << " has been graciously pardoned! 🌟"
              << ANSIColors::RESET << std::endl;
    return;
}


void PresidentialPardonForm::local_failure( void ) const
{
    return;
}