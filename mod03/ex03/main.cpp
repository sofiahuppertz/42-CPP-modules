
#include "dec/DiamondTrap.class.hpp"
#include <iostream>
#include <string>

int main ( void )
{
    std::cout << "What we've learned so far about inheritance: " << std::endl;
    std::cout << "Base class constructors are called before their derived classes" << std::endl;
    std::cout << "Base class destructors are called in reverse order" << std::endl;
    std::cout << "The diamond problem is solved by virtual inheritance" << std::endl;
    std::cout << "We have virtual functions for the getters and setters." << std::endl;
    std::cout << "That way we can overload getName() and setName() in the derived DiamondTrap class." << std::endl;
    std::cout << "Data members can be hidden in the derived class." << std::endl;
    std::cout << "_name private attribute in ClapTrap is hidden by _name private attribute in DiamondTrap" << std::endl;
    std::cout << "We can access hidden members with the scope resolution operator." << std::endl;
    std::cout << "Hidding is not the same as overriding" << std::endl;
    std::cout << std::endl;
    {
        DiamondTrap Brad_Pitt("Brad Pitt");
        std::cout << "name: " << Brad_Pitt.getName() << std::endl;
        std::cout << "clap name: " << Brad_Pitt.ClapTrap::getName() << std::endl;
        std::cout << "hit points: " << Brad_Pitt.getHitPoints() << std::endl;
        std::cout << "energy points: " << Brad_Pitt.getEnergyPoints() << std::endl;
        std::cout << "attack damage: " << Brad_Pitt.getAttackDamage() << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        DiamondTrap Angelina_Jolie("Angelina Jolie");
        DiamondTrap Shiloh(Angelina_Jolie);
        Shiloh.whoAmI();
        Shiloh.setName("Shiloh");
        std::cout << "We changed Shiloh's name to " << Shiloh.getName() << std::endl;
        Shiloh.whoAmI();
        Angelina_Jolie.attack("Shiloh");
    }
    std::cout << std::endl << std::endl;
    return 0;
}