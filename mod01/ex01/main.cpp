
#include "dec/Zombie.class.hpp"
#include "dec/zombieHorde.hpp"

int main( void )
{
    Zombie *zombies = zombieHorde(5, "Juanita");
    for (int i = 0; i < 5; i += 1)
    {
        if (zombies[i].getName() != "")
            zombies[i].anounce();   
    }
    delete [] zombies;
}