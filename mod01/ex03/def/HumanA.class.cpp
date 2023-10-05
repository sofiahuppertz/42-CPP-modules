
#include "../dec/HumanA.class.hpp"

HumanA:: HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) 
{
    std::cout << "HumanA created." << std::endl;
    return;
}

HumanA:: ~HumanA( void )
{
    std::cout << "HumanA destroyed." << std::endl;
    return;
}

void HumanA:: attack( void ) const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
    return;
}