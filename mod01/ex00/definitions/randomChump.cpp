
#include "../declarations/Zombie.class.hpp"

void randomChump( std::string name)
{
    Zombie newZombie(name);
    newZombie.anounce();
    return;
}