
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
    (void)other;
    return *this;
}

AMateria *Ice::clone( void ) const
{
    return new Ice(*this);
}

void Ice::use( ICharacter &target )
{
    std::cout << "\033[34m* shoots an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
    return;
}
