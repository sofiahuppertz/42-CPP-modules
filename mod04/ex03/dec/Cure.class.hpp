#ifndef CURE_CLASS_H
# define CURE_CLASS_H

#include "AMateria.class.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
    public:
        Cure( void );
        Cure( const Cure &other );
        virtual ~Cure( void );

        Cure &operator=( const Cure &other );

        AMateria* clone() const;
        void use( ICharacter& target );
};



#endif