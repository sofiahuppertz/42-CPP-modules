#include "../dec/WrongCat.class.hpp"

WrongCat::WrongCat ( void ): WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
    return;
}

WrongCat::WrongCat (const WrongCat &other) : WrongAnimal( other )
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    return;
}

WrongCat::~WrongCat ( void )
{
    std::cout << "WrongCat destructor called" << std::endl;
    return;
}

WrongCat &WrongCat::operator=( const WrongCat &other ) 
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound ( void ) const
{
    std::cout << "Miau miau miau" << std::endl;
    return;
}
