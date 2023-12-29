
#include "dec/ClapTrap.class.hpp"

int main( void )
{
    std::cout << std::endl << std::endl;
    {
        ClapTrap claptrap;

        claptrap.attack("Bowser");
        claptrap.takeDamage(10);
        claptrap.beRepaired(5);
        claptrap.attack("Bowser");
    }
    std::cout << std::endl << std::endl;
    {
        ClapTrap Kirby("Kirby");

        Kirby.attack("King Dedede");
        Kirby.takeDamage(5);
        Kirby.beRepaired(10);
        Kirby.attack("King Dedede");
    }
    std::cout << std::endl << std::endl;
    {
        ClapTrap PrincessPeach("Princess Peach");
    
        PrincessPeach.attack("Bowser");
        PrincessPeach.takeDamage(10);
        PrincessPeach.attack("Bowser");
    }
    std::cout << std::endl << std::endl;
    return 0;
}