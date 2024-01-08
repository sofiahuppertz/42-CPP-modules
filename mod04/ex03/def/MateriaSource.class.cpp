
#include "../dec/MateriaSource.class.hpp"

MateriaSource::MateriaSource( void ): IMateriaSource()
{
    std::cout << "MateriaSource constructor called" << std::endl;
    return;
}

MateriaSource::MateriaSource( const MateriaSource &other ) : IMateriaSource(other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    return;
}

MateriaSource::~MateriaSource( void ) 
{
    std::cout << "MateriaSource destructor called" << std::endl;
    return;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other )
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &other)
    {
        IMateriaSource::operator=(other);
    }
    return *this;
}


void MateriaSource::learnMateria( AMateria *m )
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            return;
        }
    }
    return;
}

AMateria *MateriaSource::createMateria( std::string const &type )
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] && this->_inventory[i]->getType() == type)
            return this->_inventory[i]->clone();
    }
    return NULL;
}
