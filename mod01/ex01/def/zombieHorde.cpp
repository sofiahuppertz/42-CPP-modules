
#include "../dec/zombieHorde.hpp"


Zombie *zombieHorde ( int N, std::string name)
{
    try 
    {
        Zombie *zombies = new Zombie[N];
        for (int i = 0; i < N; i += 1)
        {
            zombies[i].setName(name);
        }
        return zombies;
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl; 
    }
    return nullptr;

}