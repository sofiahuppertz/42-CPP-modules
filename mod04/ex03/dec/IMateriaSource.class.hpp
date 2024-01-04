#ifndef IMATERIASOURCE_CLASS_H
# define IMATERIASOURCE_CLASS_H


#include "AMateria.class.hpp"
#include "ICharacter.class.hpp"
#include <iostream>
#include <string>

class IMateriaSource
{
    protected:
        AMateria *_inventory[4];
    public:
        IMateriaSource( void );
        IMateriaSource( const IMateriaSource &other );
        virtual ~IMateriaSource();

        IMateriaSource &operator=( const IMateriaSource &other );

        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
