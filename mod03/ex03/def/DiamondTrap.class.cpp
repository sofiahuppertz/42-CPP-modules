
#include "../dec/DiamondTrap.class.hpp"
#include <iostream>
#include <string>


DiamondTrap::DiamondTrap ( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap: default constructor called" << std::endl;
    this->setName("DiamondTrap (default)");
    ClapTrap::setName("DiamondTrap (default)_clap_name");
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(ScavTrap::getAttackDamage());
    return;
}

DiamondTrap::DiamondTrap ( std::string name ) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap: " << name << " constructor called" << std::endl;
    this->setName(name);
    ClapTrap::setName(name + "_clap_name");
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(ScavTrap::getAttackDamage());
    return;
}

DiamondTrap::DiamondTrap ( const DiamondTrap &other ) : ScavTrap(other), FragTrap(other)
{
    this->setName(other.getName());
    ClapTrap::setName(this->getName() + "_clap_name");
    std::cout << "DiamondTrap: copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap ( void )
{
    std::cout << "DiamondTrap: destructor called" << std::endl;
    return;
}


// Setters and Getters 


void DiamondTrap::setName ( std::string name )
{
    this->_name = name;
    this->ClapTrap::setName(name + "_clap_name");
    return;
}

std::string DiamondTrap::getName ( void ) const
{
    return this->_name;
}


// Member functions

void DiamondTrap::attack(std::string const & target) {
    ScavTrap::attack(target);
    std::cout << "DiamondTrap: " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    return;
}

void DiamondTrap::whoAmI ( void )
{
    std::cout << "DiamondTrap: " << this->getName() << " says: My name is " << this->getName() << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
    return;
}