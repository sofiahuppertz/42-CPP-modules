#include "../dec/Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat( std::string _name, int _grade): name(_name), grade(_grade)
{
    std::cout<< "Calling constructor" << std::endl;
    if ( _grade < 1)
    {
        throw GradeTooHighException();
    }
    if ( _grade > 150 )
    {
        throw GradeTooLowException();
    }
    return;
}

Bureaucrat::Bureaucrat (const Bureaucrat &other): name(other.name), grade(other.grade)
{
    return;
}

Bureaucrat::~Bureaucrat( void )
{
    return;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        grade = other.grade;
    }
    return *this;
}

std::string Bureaucrat::getName( void )  const
{
    return name;

}

int Bureaucrat::getGrade( void ) const
{
    return grade;
}

void Bureaucrat::incrementGrade( void )
{
    std::cout << "Calling incrementGrade()" << std::endl;
    grade--;
    if ( grade < 1)
    {
        throw GradeTooHighException();
    }
    return;
}

void Bureaucrat::decrementGrade( void )
{
    std::cout << "Calling decrementGrade()" << std::endl;
    grade++;
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
    return;
}

void Bureaucrat::signAForm( AForm &f )
{
    std::cout << "Calling signForm()" << std::endl;
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << name << " coulndn't sign " << f.getName() << ". Reason: " <<  e.what() << std::endl;
    }
}

void Bureaucrat::executeForm( AForm const &form )
{
    std::cout << "Calling executeForm()" << std::endl;
    try {
        if (getGrade() >  form.getGradeToExecute())
        {
            throw GradeTooLowException();
        }
        if (form.getIsSigned() == "False")
        {
            throw FormNotSignedException();
        }
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e ){
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Operator overload
std::ostream& operator<< (std::ostream& os, const Bureaucrat &object)
{
    os << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
    return os;
}