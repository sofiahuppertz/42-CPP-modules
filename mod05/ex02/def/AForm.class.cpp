#include "../dec/AForm.class.hpp"


AForm::AForm( void ): name("Default"), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Calling default AForm constructor." << std::endl;
    isSigned = false;
    return ;
}

AForm::AForm(std::string _name, int _greadeToSign, int _gradeToExecute): name(_name), gradeToSign(_greadeToSign), gradeToExecute(_gradeToExecute) {
    std::cout << "Calling AForm constructor." << std::endl;
    isSigned = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Calling AForm copy constructor." << std::endl;
    isSigned = other.isSigned;
    return ;
}

AForm &AForm::operator=(AForm const &other)
{
    std::cout << "Calling AForm assignment operator." << std::endl;
    (void)other;
    return *this;
}

AForm::~AForm(void )
{
    return;
}
        
bool AForm::beSigned( Bureaucrat const &b )
{
    std::cout << "Calling beSigned()" << std::endl;
    try
    {
        if (b.getGrade() > gradeToSign)
        {
            throw GradeTooLowException();
        }
        isSigned = true;
        return true;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

std::string AForm::getName( void ) const
{
    return name;
}

int AForm::getGradeToExecute( void ) const
{
    return gradeToExecute;
}

int AForm::getGradeToSign( void ) const
{
    return gradeToSign;
}

std::string AForm::getIsSigned( void ) const
{
    if (isSigned)
        return "True";
    return "False";
}

void AForm::setTarget(std::string _target)
{
    target = _target;
}

std::string AForm::getTarget( void ) const
{
    return target;
}

void AForm::check_and_execute(Bureaucrat const &executor)
{
    try {
        if (executor.getGrade() >  getGradeToExecute())
        {
            throw GradeTooLowException();
        }
        if (getIsSigned() == "False")
        {
            throw FormNotSignedException();
        }
        execute(executor);
    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        failure();
    }
    return ;
}

std::ostream& operator<< (std::ostream& os, const AForm &object)
{
    os << "AForm: " << object.getName() << "; Grade to execute: " << object.getGradeToExecute() << "; Grade to sign: " << object.getGradeToSign() << "; Is signed: " << object.getIsSigned();
    return os;
}