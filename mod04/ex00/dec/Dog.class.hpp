#ifndef DOG_CLASS_H
# define DOG_CLASS_H

#include "Animal.class.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
    public:
        Dog ( void );
        Dog ( const Dog &other);
        ~Dog ( void );

        Dog &operator=(const Dog &other);

        void makeSound( void ) const;
};


#endif