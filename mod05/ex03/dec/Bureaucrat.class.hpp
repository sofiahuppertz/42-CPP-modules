#ifndef BUREAUCRAT_CLASS_H
#define BUREAUCRAT_CLASS_H

#include <string>
#include <iostream>
#include "AForm.class.hpp"
#include "Exceptions.hpp"

class AForm;

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
        void incrementGrade( void );
        void decrementGrade( void );
        void signAForm( AForm &f );

        // New function
        void executeForm( AForm const &form );

    private:
        const std::string name;
        int grade;

};

std::ostream& operator<< (std::ostream& os, const Bureaucrat &object);


# endif