
#include "../dec/FragTrap.class.hpp"

// Constructors

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap: default constructor called" << std::endl;
    this->setName("FragTrap (default)");
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap: " << name << " constructor called" << std::endl;
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    return;
}

FragTrap::FragTrap( const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap: copy constructor called" << std::endl;
}

// Destructor

FragTrap::~FragTrap(void) 
{
    std::cout << "FragTrap: Destructor called" << std::endl;
}

// Copy assignment operator

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap: assignement operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Member functions

void FragTrap::highFivesGuys ( void )
{
    std::cout << "FragTrap: " << this->getName() << " says: High five, guys!" << std::endl;
    return;
}