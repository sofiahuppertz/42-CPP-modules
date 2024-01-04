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
        virtual Brain *getBrain( void ) const;
        virtual void setIdea( std::string idea, int index );
        virtual std::string getIdea( int index ) const;

    protected:
        std::string _type;
};

#endif