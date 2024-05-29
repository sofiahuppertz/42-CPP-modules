#ifndef FORM_CLASS_H
# define FORM_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form {

    public:
        // Constructors, destructor and operator=
        Form ( void );
        Form(std::string _name, int _greadeToSign, int _gradeToExecute);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form( void );

        // Getters
        std::string getName( void ) const;
        std::string getIsSigned( void ) const;
        int getGradeToExecute( void ) const;
        int getGradeToSign( void ) const;

        // Member functions
        bool beSigned( Bureaucrat const &b );

        // Exceptions
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

};


std::ostream& operator<< (std::ostream& os, const Form &object);

# endif