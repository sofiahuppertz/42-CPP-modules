#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

#include <fstream>
#include <string>
#include "Bureaucrat.class.hpp"
#include "Exceptions.hpp"

class Bureaucrat;

class AForm {

    public:
        //constructors
        AForm( void );
        AForm(std::string _name, int _greadeToSign, int _gradeToExecute);
        AForm(AForm const &other);

        // copy
        AForm &operator=(AForm const &other);
        virtual ~AForm( void ) = 0;
        bool beSigned( Bureaucrat const &b );

        // Accessors
        std::string getName( void ) const;
        std::string getIsSigned( void ) const;
        int getGradeToExecute( void ) const;
        int getGradeToSign( void ) const;
        std::string getTarget( void ) const;

        // execute
        void execute(Bureaucrat const &executor) const;
        virtual void local_execute(Bureaucrat const &executor) const = 0;
        virtual void local_failure( void ) const = 0;

        //setter
        void setTarget(std::string _target);


    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        std::string target;

};


std::ostream& operator<< (std::ostream& os, const AForm &object);

# endif