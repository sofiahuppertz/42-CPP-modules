#ifndef CAT_CLASS_H
# define CAT_CLASS_H

#include "Animal.class.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
    public:
        Cat ( void );
        Cat ( const Cat &other);
        ~Cat ( void );

        Cat &operator=( const Cat &other );

        void makeSound( void ) const;

};


#endif