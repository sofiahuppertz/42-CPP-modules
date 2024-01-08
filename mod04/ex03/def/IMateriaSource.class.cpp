
#include "../dec/IMateriaSource.class.hpp"

IMateriaSource::IMateriaSource( void )
{
    std::cout << "IMateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    return;
}

IMateriaSource::IMateriaSource( const IMateriaSource &other )
{
    std::cout << "IMateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
    }
    return;
}

IMateriaSource::~IMateriaSource( void )
{
    std::cout << "IMateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    return;
}

IMateriaSource &IMateriaSource::operator=( const IMateriaSource &other )
{
    std::cout << "IMateriaSource copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
            if (other._inventory[i])
            {
                this->_inventory[i] = other._inventory[i]->clone();
            }                
        }
    }
    return *this;
}


