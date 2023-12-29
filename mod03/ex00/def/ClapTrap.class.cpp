
#include "../dec/ClapTrap.class.hpp"

// Constructor

ClapTrap::ClapTrap(void) : _name("Steve (default)"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap: " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other) {
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap: Destructor called" << std::endl;
}

// Copy Assignement Operator

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap assignement operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Member Functions

void ClapTrap::attack(std::string const & target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints -= 1;
    }
    else if (this->_energyPoints <= 0)
        std::cout << "ClapTrap: " << this->_name << " is out of energy!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << "ClapTrap: " << this->_name << " is dead!" << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
        std::cout << "ClapTrap: " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    this->_hitPoints -= amount;
    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " is repaired for " << amount << " points of health!" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
    }
    else if (this->_energyPoints <= 0)
        std::cout << "ClapTrap: " << this->_name << " is out of energy!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << "ClapTrap: " << this->_name << " is dead!" << std::endl;
    return;
}
