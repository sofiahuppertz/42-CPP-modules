
#include "../dec/Ice.class.hpp"

Ice::Ice( void ) : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
    return;
}

Ice::Ice( const Ice &other ) : AMateria(other)
{
    std::cout << "Ice copy constructor called" << std::endl;
    return;
}

Ice::~Ice( void )
{
    std::cout << "Ice destructor called" << std::endl;
    return;
}

Ice &Ice::operator=( const Ice &other )
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    return *this;
}

AMateria *Ice::clone( void ) const
{
    return new Ice(*this);
}

void Ice::use( ICharacter &target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}
