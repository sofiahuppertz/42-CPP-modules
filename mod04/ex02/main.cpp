
#include "dec/AAnimal.class.hpp"
#include "dec/Brain.class.hpp"
#include "dec/Cat.class.hpp"
#include "dec/Dog.class.hpp"


int main ( void )
{
    {   
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 1--------" << std::endl;
        AAnimal* animals[4];
        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < 4; i++)
        {
            animals[i]->makeSound();
        }
        for (int i = 0; i < 4; i++)
        {
            delete animals[i];
        }
    }
    {
        // I can't compile the code if I try to instantiate an abstract class... that's the whole point.
        // AAnimal animal;
        // animal.makeSound();
    }
    return 0;
}
