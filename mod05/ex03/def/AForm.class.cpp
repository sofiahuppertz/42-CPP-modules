#include "../dec/AForm.class.hpp"

AForm::AForm( void ): name("Default"), gradeToSign(150), gradeToExecute(150)
{
    isSigned = false;
    return ;
}


AForm::AForm(std::string _name, int _greadeToSign, int _gradeToExecute): name(_name), gradeToSign(_greadeToSign), gradeToExecute(_gradeToExecute) {
    isSigned = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    isSigned = other.isSigned;
    return ;
}

AForm &AForm::operator=(AForm const &other)
{
    (void)other;
    return *this;
}

AForm::~AForm(void )
{
    return;
}
        

// Accessors 

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
        return "Yes";
    return "No";
}

void AForm::setTarget(std::string _target)
{
    target = _target;
}

std::string AForm::getTarget( void ) const
{
    return target;
}


// beSigned that checks if the bureaucrat has the right grade to sign the form and sets isSigned to true

bool AForm::beSigned( Bureaucrat const &b )
{
    if (b.getGrade() > gradeToSign)
    {
        throw AForm::GradeTooLowException();
        return false;
    }
    isSigned = true;
    return true;
}

// Execute that calls local_execute and local_failure

void AForm::execute(Bureaucrat const &executor) const
{
    try {
        if (executor.getGrade() >  getGradeToExecute())
        {
            throw AForm::GradeTooLowException();
        }
        if (getIsSigned() == "False")
        {
            throw AForm::NotSignedException();
        }
        local_execute(executor);
    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        local_failure();
    }
    return ;
}

// Operator Overload

std::ostream& operator<<(std::ostream& os, const AForm& object) {
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE << "Form: " << ANSIColors::CYAN << object.getName() << ANSIColors::WHITE << " | ";
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE << "Grade to execute: " << ANSIColors::CYAN << object.getGradeToExecute()<< ANSIColors::WHITE << " | ";
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE<< "Grade to sign: " << ANSIColors::CYAN << object.getGradeToSign()<< ANSIColors::WHITE << " | ";
    os << ANSIColors::BRIGHT_BACKGROUND_BLUE  << ANSIColors::WHITE<< "Is signed: "  << ANSIColors::CYAN  << object.getIsSigned()<< ANSIColors::WHITE << " | " << ANSIColors::RESET;
    return os;
}


// Exceptions

const char *AForm::GradeTooHighException::what()const throw()
{
    return "STOP: Excessive grade.";
}


const char *AForm::GradeTooLowException::what()const throw()
{
    return "Insufficient grade.";
}

const char *AForm::NotSignedException::what()const throw()
{
    return "You need to sign this form before executing it.";
}