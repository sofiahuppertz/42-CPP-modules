
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
    (void)other;
    return *this;
}

AMateria *Cure::clone( void ) const
{
    return new Cure(*this);
}

void Cure::use( ICharacter &target )
{
    std::cout << "\033[35m* heals " << target.getName() << "'s wounds *\033[0m" << std::endl;
    return;
}