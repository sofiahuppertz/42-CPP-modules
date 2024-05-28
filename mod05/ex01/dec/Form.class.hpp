#ifndef FORM_CLASS_H
# define FORM_CLASS_H

#include <string>
#include "Bureaucrat.class.hpp"
#include "Exceptions.hpp"

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

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

};


std::ostream& operator<< (std::ostream& os, const Form &object);

# endif