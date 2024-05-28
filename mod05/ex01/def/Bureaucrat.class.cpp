#include "../dec/Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat( void ):name("Default"), grade(150)
{
    std::cout<< "Calling default constructor" << std::endl;
    return;
}

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
    if ( grade <= 1)
    {
        throw GradeTooHighException();
    }
    grade--;
    return;
}

void Bureaucrat::decrementGrade( void )
{
    std::cout << "Calling decrementGrade()" << std::endl;
    if (grade >= 150)
    {
        throw GradeTooLowException();
    }
    grade++;
    return;
}

void Bureaucrat::signForm( Form &f )
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

// Operator overload
std::ostream& operator<< (std::ostream& os, const Bureaucrat &object)
{
    os << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
    return os;
}