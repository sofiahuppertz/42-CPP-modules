
#include "../dec/Cure.class.hpp"

Cure::Cure( void ) : AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
    return;
}

Cure::Cure( const Cure &other ) : AMateria(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
    return;
}

Cure::~Cure( void )
{
    std::cout << "Cure destructor called" << std::endl;
    return;
}

Cure &Cure::operator=( const Cure &other )
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    return *this;
}

AMateria *Cure::clone( void ) const
{
    return new Cure(*this);
}

void Cure::use( ICharacter &target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return;
}