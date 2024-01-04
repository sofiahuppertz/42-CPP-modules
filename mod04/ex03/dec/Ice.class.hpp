#ifndef ICE_CLASS_H
# define ICE_CLASS_H

#include "AMateria.class.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{
    public:
        Ice( void );
        Ice( const Ice &other );
        virtual ~Ice( void );

        Ice &operator=( const Ice &other );

        AMateria* clone() const;
        void use( ICharacter& target );
};


#endif