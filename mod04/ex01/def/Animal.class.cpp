
#include "../dec/Animal.class.hpp"

Animal::Animal ( void ) : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
    return;
}

Animal::Animal ( std::string type): _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
    return;
}

Animal::Animal( const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->_type = other._type;
}


Animal::~Animal ( void )
{
    std::cout << "Animal destructor called" << std::endl;
    return;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void Animal::makeSound ( void ) const
{
    std::cout << "*Any animal sound*" << std::endl;
    return;
}

std::string Animal::getType ( void ) const
{
    return this->_type;
}

Brain *Animal::getBrain( void ) const
{
    return NULL;
}

void Animal::setIdea ( std::string idea, int index)
{
    (void)idea;
    (void)index;
    return;
}

std::string Animal::getIdea ( int index ) const
{
    (void)index;
    return "";
}