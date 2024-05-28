#include "../dec/Exceptions.hpp"


const char *GradeTooHighException::what()const throw()
{
    return   "Grade is Too High." ;
}

const char *GradeTooLowException::what()const throw()
{
    return "Grade Too Low.";
}