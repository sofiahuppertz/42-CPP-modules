
#include "dec/FragTrap.class.hpp"
#include "dec/ClapTrap.class.hpp"

int main ( void )
{
    {
        FragTrap fragtrap("Elon Musk");
        fragtrap.attack("Mark Zuckerberg");
        fragtrap.takeDamage(5);
        fragtrap.takeDamage(5);
        fragtrap.beRepaired(5);
        fragtrap.highFivesGuys();
    }
}