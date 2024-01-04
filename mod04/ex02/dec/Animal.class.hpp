#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

#include "Brain.class.hpp"
#include <iostream>
#include <string>

class Animal {
    public:
        Animal ( void );
        Animal ( std::string type );
        Animal (const Animal &other);
        virtual ~Animal ( void );

        Animal &operator=(const Animal &other);
        std::string getType ( void )const;
        virtual void makeSound ( void ) const;  
        // These are pure virtual functions.
        // A class with at least one pure virtual function is called an abstract class.
        // An abstract class cannot be instantiated.
        virtual Brain *getBrain( void ) const = 0;
        virtual void setIdea( std::string idea, int index ) = 0;
        virtual std::string getIdea( int index ) const = 0;

    protected:
        std::string _type;
};

#endif