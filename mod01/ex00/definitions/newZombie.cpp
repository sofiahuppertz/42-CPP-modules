
#include "../declarations/Zombie.class.hpp"


Zombie* newZombie( std::string name )
{
    try 
    {
        Zombie *newZombie = new Zombie(name);
        return newZombie;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;    
    }
    return NULL;
}
