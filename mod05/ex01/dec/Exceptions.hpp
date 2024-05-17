#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class GradeTooHighException: public std::exception {
    public:
        virtual const char *what() const throw();
};

class GradeTooLowException: public std::exception {
    public:
        virtual const char *what() const throw();
};

# endif
