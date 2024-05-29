#ifndef BUREAUCRAT_CLASS_H
#define BUREAUCRAT_CLASS_H

#include <string>
#include <iostream>
#include <exception>
#include "ANSIColors.hpp"
#include "Form.class.hpp"

class Form;

class Bureaucrat {

    public:

        // OCF
        Bureaucrat( void );
        Bureaucrat( std::string _name, int _grade );
        Bureaucrat (const Bureaucrat &other);
        ~Bureaucrat( void );
        Bureaucrat &operator=(const Bureaucrat &other);

        // Getters
        std::string getName( void )  const;
        int getGrade( void ) const;

        // Memeber functions
        void incrementGrade( int amount );
        void decrementGrade( int amount );

        // New function
        void signForm( Form &f );

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
        int grade;

};

std::ostream& operator<< (std::ostream& os, const Bureaucrat &object);


# endif