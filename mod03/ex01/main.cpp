
#include "dec/ScavTrap.class.hpp"
#include "dec/ClapTrap.class.hpp"


int main( void )
{
    {
        ScavTrap scavtrap("Mike Tyson");
        
        scavtrap.attack("Donald Trump");
        scavtrap.takeDamage(10);
        scavtrap.beRepaired(10);
        scavtrap.guardGate();
    }
    std::cout << std::endl;
    {
        ScavTrap scavtrap("Mohamed Ali");

        scavtrap.attack("Joe Frazier");
        scavtrap.guardGate();
        scavtrap.takeDamage(100);
        scavtrap.attack("Joe Frazier");
    }
    std::cout << std::endl;
    return 0;
}