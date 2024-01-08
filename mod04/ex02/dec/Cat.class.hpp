#ifndef CAT_CLASS_H
# define CAT_CLASS_H

#include "AAnimal.class.hpp"
#include "Brain.class.hpp"
#include <iostream>
#include <string>

class Cat : public AAnimal {
    public:
        Cat ( void );
        Cat ( const Cat &other);
        ~Cat ( void );

        Cat &operator=( const Cat &other );

        void makeSound( void ) const;
        Brain *getBrain( void ) const;
        void setIdea( std::string idea, int index );
        std::string getIdea( int index ) const;
    
    private:
            Brain *brain;

};


#endif