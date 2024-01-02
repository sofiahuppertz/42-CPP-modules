
#include "../dec/Cat.class.hpp"

Cat::Cat ( void ): Animal()
{
    _type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
    return;
}

Cat::Cat (const Cat &other) : Animal( other )
{
    std::cout << "Cat copy constructor called" << std::endl;
    return;
}

Cat::~Cat ( void )
{
    std::cout << "Cat destructor called" << std::endl;
    return;
}

Cat &Cat::operator=( const Cat &other ) 
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Cat::makeSound ( void ) const
{
    std::cout << "Miau miau miau" << std::endl;
    return;
}