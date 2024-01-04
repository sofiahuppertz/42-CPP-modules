
#include "../dec/Character.class.hpp"

Character::Character( void ): ICharacter(), _name("default"), _count(0)
{
    std::cout << "Character constructor called" << std::endl;
    return;
}

Character::Character( std::string const name ): ICharacter(), _name(name), _count(0)
{
    std::cout << "Character constructor called" << std::endl;
    return;
}

Character::Character( const Character &other ): ICharacter(other), _name(other._name), _count(other._count)
{
    std::cout << "Character copy constructor called" << std::endl;
    return;
}

Character::~Character( void )
{
    std::cout << "Character destructor called" << std::endl;
    return;
}

Character &Character::operator=( const Character &other )
{
    std::cout << "Character copy assignment operator called" << std::endl;
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
        this->_count = other._count;
    }
    return *this;
}

std::string const &Character::getName( void ) const
{
    return this->_name;
}

void Character::equip( AMateria *m )
{
    if (_count == 4 || !m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            _count++;
            break;
        }
    }
    return;
}

void Character::unequip( int idx )
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return;
    _inventory[idx] = NULL;
    _count--;
    return;
}

void Character::use( int idx, ICharacter &target )
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
    return;
}