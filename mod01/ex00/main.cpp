#include <iostream>
#include "declarations/Zombie.class.hpp"
#include "declarations/newZombie.hpp"
#include "declarations/randomChump.hpp"

int main(void)
{
    std::cout << "This exercise is about creating zombies in the heap and in the stack; 'Zombie' is actually just a C++ class." << std::endl << std::endl;
    Zombie rickGrimes("Rick Grimes");
    std::cout << "A zombie has just been created in the main function (In the stack)" << std::endl;
    rickGrimes.anounce();
    std::cout << std::endl;

    Zombie *darylDixon = newZombie("Daryl Dixon");
    std::cout << "A zombie has just bee created with the newZombie function (In the Heap)" << std::endl;
    darylDixon->anounce();
    std::cout << std::endl;

    Zombie *michonne = newZombie("Michonne");
    std::cout << "A zombie has just bee created with the newZombie function (In the Heap)" << std::endl;
    michonne->anounce();
    std::cout << std::endl;



    std::cout << "A zombie is about to be created with the randomChump function (In the stack)" << std::endl;
    randomChump("Maggie Greene");
    std::cout << "This zombie died when the randomChump function returned, because it was out of it's scope. When a class gets out of it's scope, it's automatically destroyed..." << std::endl << std::endl;
    

    std::cout << "Zombies allocated in the heap where created with the 'New' keyword, it's like malloc() in C..." << std::endl << std::endl;
    std::cout << "Now we will delete the zombies created with the newZombie() function" << std::endl;
    delete darylDixon;
    delete michonne;
    std::cout << std::endl;

    std::cout << "Remember we created a zombie in the main function ?  Now we will return and it will automatically be deleted." << std::endl;
    return 0;
}