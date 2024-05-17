#include "../dec/Form.class.hpp"

Form::Form( void ): name("Default"), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Calling default constructor." << std::endl;
    isSigned = false;
    return;
}

Form::Form(std::string _name, int _greadeToSign, int _gradeToExecute): name(_name), gradeToSign(_greadeToSign), gradeToExecute(_gradeToExecute) {
    std::cout << "Calling Form constructor." << std::endl;
    isSigned = false;
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
        
bool Form::beSigned( Bureaucrat &b )
{
    std::cout << "Calling beSigned()" << std::endl;
    if (b.getGrade() <= gradeToSign)
    {
        isSigned = true;
        return true;
    }
    throw GradeTooLowException();
    return false;   
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
        return "True";
    return "False";
}

std::ostream& operator<< (std::ostream& os, const Form &object)
{
    os << "Form: " << object.getName() << "; Grade to execute: " << object.getGradeToExecute() << "; Grade to sign: " << object.getGradeToSign() << "; Is signed: " << object.getIsSigned();
    return os;
}