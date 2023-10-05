
#include "../dec/Weapon.class.hpp"

Weapon::Weapon( std::string type) : _type(type) 
{
    std::cout << "Weapon created" << std::endl;
    return;
}

Weapon::~Weapon( void ) 
{
    std::cout << "Weapon destroyed" << std::endl;
    return;
}

void Weapon::setType ( std::string type) 
{
    this->_type = type;
    return;
}

std::string Weapon::getType ( void ) const 
{
    return this->_type;
}