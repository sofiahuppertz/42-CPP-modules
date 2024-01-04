#include "../dec/WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal ( void ) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal ( std::string type): _type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    _type = other._type;
}

WrongAnimal::~WrongAnimal ( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void WrongAnimal::makeSound ( void ) const
{
    std::cout << "*Any wrong animal sound*" << std::endl;
    return;
}

std::string WrongAnimal::getType ( void ) const
{
    return this->_type;
}