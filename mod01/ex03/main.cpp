
#include "dec/Weapon.class.hpp"
#include "dec/HumanA.class.hpp"
#include "dec/HumanB.class.hpp"

int main() 
{
   {
        Weapon  club = Weapon("crude spiked club");
        HumanA bob("Bob", club);

        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    } 
    {
        Weapon  club = Weapon("crude spiked club");
        HumanB jim("Jim");

        jim.attack(); // This has no effect because jim instance doesn't have a weapon yet.
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0; 
}