
#include "../dec/ScavTrap.class.hpp"

// Constructors

ScavTrap::ScavTrap(void) : ClapTrap(),  _name("ScavTrap (default)"), _hitPoints(100), _energyPoints(50), attackDamage(20) {
    std::cout << "ScavTrap: default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _name(name), _hitPoints(100), _energyPoints(50), attackDamage(20) {
    std::cout << "ScavTrap: " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap: copy constructor called" << std::endl;
}

// Destructor

ScavTrap::~ScavTrap(void) : {
    std::cout << "ScavTrap: destructor called" << std::endl;
}

// Copy assignment operator

ScavTrap &ScavTrap::operator=(const ScavTrap &other):
{
    std::cout << "ScavTrap: assignement operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Member functions

void ScavTrap::attack : ClapTrap()
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ScavTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints -= 1;
    }
    else if (this->_energyPoints <= 0)
        std::cout << "ScavTrap: " << this->_name << " is out of energy!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << "ScavTrap: " << this->_name << " is dead!" << std::endl;
    return;
}

