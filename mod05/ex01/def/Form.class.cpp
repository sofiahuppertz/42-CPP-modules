#include "../dec/Form.class.hpp"

Form::Form( void ): name("Default"), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Calling default constructor." << std::endl;
    isSigned = false;
    return;
}

Form::Form(std::string _name, int _gradeToSign, int _gradeToExecute): name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    isSigned = other.isSigned;
    return ;
}

Form &Form::operator=(Form const &other)
{
    (void)other;
    return *this;
}

Form::~Form(void )
{
    return;
}

bool Form::beSigned( Bureaucrat const &b )
{
    if (b.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
        return false;
    }
    isSigned = true;
    return true;
}

std::string Form::getName( void ) const
{
    return name;
}

int Form::getGradeToExecute( void ) const
{
    return gradeToExecute;
}

int Form::getGradeToSign( void ) const
{
    return gradeToSign;
}

std::string Form::getIsSigned( void ) const
{
    if (isSigned)
        return "Yes";
    return "No ";
}

std::ostream& operator<<(std::ostream& os, const Form& object) {
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE << "Form: " << ANSIColors::CYAN << object.getName() << ANSIColors::WHITE << " | ";
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE << "Grade to execute: " << ANSIColors::CYAN << object.getGradeToExecute()<< ANSIColors::WHITE << " | ";
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE<< "Grade to sign: " << ANSIColors::CYAN << object.getGradeToSign()<< ANSIColors::WHITE << " | ";
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE<< "Is signed: "  << ANSIColors::CYAN  << object.getIsSigned()<< ANSIColors::WHITE << " | " << ANSIColors::RESET;
    return os;
}
