
#include "../dec/AAnimal.class.hpp"

AAnimal::AAnimal ( void ) : _type("AAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
    return;
}

AAnimal::AAnimal ( std::string type): _type(type)
{
    std::cout << "AAnimal constructor called" << std::endl;
    return;
}

AAnimal::AAnimal( const AAnimal &other)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    this->_type = other._type;
}


AAnimal::~AAnimal ( void )
{
    std::cout << "AAnimal destructor called" << std::endl;
    return;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void AAnimal::makeSound ( void ) const
{
    std::cout << "*Any animal sound*" << std::endl;
    return;
}

std::string AAnimal::getType ( void ) const
{
    return this->_type;
}

