
#include "../dec/Dog.class.hpp"

Dog::Dog ( void ): Animal()
{
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    return;
}

Dog::Dog (const Dog &other) : Animal( other )
{
    std::cout << "Dog copy constructor called" << std::endl;
    return;
}

Dog::~Dog ( void )
{
    std::cout << "Dog destructor called" << std::endl;
    return;
}

Dog &Dog::operator=( const Dog &other ) 
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Dog::makeSound ( void ) const
{
    std::cout << "Wouf! Wouf! Wouf!" << std::endl;
    return;
}

