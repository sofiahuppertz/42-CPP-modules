#ifndef DOG_CLASS_H
# define DOG_CLASS_H

#include "Animal.class.hpp"
#include "Brain.class.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
    public:
        Dog ( void );
        Dog ( const Dog &other);
        ~Dog ( void );

        Dog &operator=(const Dog &other);

        void makeSound( void ) const;
        Brain *getBrain( void ) const;
        void setIdea( std::string idea, int index );
        std::string getIdea( int index ) const;
    
    private:

        Brain *brain;
};


#endif