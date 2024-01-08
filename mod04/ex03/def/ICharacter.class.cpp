
#include "../dec/ICharacter.class.hpp"

ICharacter::ICharacter( void )
{
    std::cout << "ICharacter constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    return;
}

ICharacter::ICharacter( std::string const name )
{
    std::cout << "ICharacter constructor called" << std::endl;
    (void)name;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    return;
}

ICharacter::ICharacter( const ICharacter &other )
{
    std::cout << "ICharacter copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone(); 
    }
    return;
}

ICharacter::~ICharacter( void )
{
    for(int i = 0; i < 4; ++i) {
        _inventory[i] = NULL; 
    }
    std::cout << "ICharacter destructor called" << std::endl;
    return;
}

ICharacter &ICharacter::operator=( const ICharacter &other )
{
    std::cout << "ICharacter copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
            {
                delete this->_inventory[i];
                this->_inventory[i] = other._inventory[i]->clone();
            }                
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}