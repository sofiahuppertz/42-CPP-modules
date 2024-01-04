#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

# include "ICharacter.class.hpp"
# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
    protected:
        const std::string _type;

    public:
        AMateria( void );
        AMateria( std::string const & type );
        AMateria( const AMateria &other );
        virtual ~AMateria( void );

        AMateria &operator=( const AMateria &other );

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use( ICharacter& target) ;
};


#endif