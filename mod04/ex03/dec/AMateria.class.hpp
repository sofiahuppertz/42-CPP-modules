#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

# include <iostream>
# include <string>

class AMateria
{
    protected:

    public:
        AMateria( void ):
        AMateria( std::string const & type);
        AMateria( const AMateria &other );
        virtual ~AMateria( void );

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
}


#endif