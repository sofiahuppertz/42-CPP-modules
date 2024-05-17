#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

#include <fstream>
#include <string>
#include "Bureaucrat.class.hpp"
#include "Exceptions.hpp"

class Bureaucrat;

class AForm {

    public:
        AForm( void );
        AForm(std::string _name, int _greadeToSign, int _gradeToExecute);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        virtual ~AForm( void ) = 0;
        bool beSigned( Bureaucrat const &b );
        std::string getName( void ) const;
        std::string getIsSigned( void ) const;
        int getGradeToExecute( void ) const;
        int getGradeToSign( void ) const;
        void check_and_execute(Bureaucrat const &executor);
        virtual void execute(Bureaucrat const &executor) const = 0;
        virtual void failure( void ) = 0;
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

};


std::ostream& operator<< (std::ostream& os, const AForm &object);

# endif