
#include "../dec/ScavTrap.class.hpp"

// Constructors

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap: default constructor called" << std::endl;
    this->setName("ScavTrap (default)");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap: " << name << " constructor called" << std::endl;
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    return;
}

ScavTrap::ScavTrap( const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap: copy constructor called" << std::endl;
}

// Destructor

ScavTrap::~ScavTrap(void) 
{
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

// Copy assignment operator

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap: assignement operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Member functions

void ScavTrap::attack (std::string const & target)
{
    ClapTrap::attack(target);
    if (this->checkStatus()) 
    {
        std::cout << "ScavTrap: " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
    return;
}

void ScavTrap::guardGate(void)
{
    if (this->checkStatus())
    {
        std::cout << "ScavTrap: " << this->getName() << " is in Gate keeper mode." << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
    return;
}