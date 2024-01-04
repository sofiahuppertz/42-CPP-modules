
#include "../dec/AMateria.class.hpp"

AMateria::AMateria( void ): _type("default")
{
    std::cout << "AMateria constructor called" << std::endl;
    return;
}

AMateria::AMateria( std::string const & type ): _type(type)
{
    std::cout << "AMateria constructor called" << std::endl;
    return;
}

AMateria::AMateria( const AMateria &other ) : _type(other._type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    return;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria destructor called" << std::endl;
    return;
}

AMateria &AMateria::operator=( const AMateria &other )
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use( ICharacter& target )
{
    (void)target;
    return;
}