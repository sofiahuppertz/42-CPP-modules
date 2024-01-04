#ifndef ICHARACTER_CLASS_H
# define ICHARACTER_CLASS_H

#include "AMateria.class.hpp"
#include <iostream>
#include <string>

class AMateria;

class ICharacter 
{
    protected:
        AMateria *_inventory[4];

    public:
        ICharacter( void );
        ICharacter( std::string const name );
        ICharacter( const ICharacter &other );
        virtual ~ICharacter( void );

        ICharacter &operator=( const ICharacter &other );

        virtual std::string const & getName() const = 0;
        virtual void equip( AMateria* m ) = 0;
        virtual void unequip( int idx ) = 0;
        virtual void use( int idx, ICharacter& target ) = 0;

};

#endif

