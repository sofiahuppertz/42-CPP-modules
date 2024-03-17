
#include "../dec/HumanB.class.hpp"

HumanB::HumanB(std::string name)
	: _name(name)
{
	this->_weapon = NULL;
	std::cout << "HumanB created." << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destroyed." << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " doesn't have a weapon" << std::endl;
	}
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}