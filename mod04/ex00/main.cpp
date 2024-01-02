
#include "dec/Animal.class.hpp"
#include "dec/Cat.class.hpp"
#include "dec/Dog.class.hpp"
#include "dec/WrongAnimal.class.hpp"
#include "dec/WrongCat.class.hpp"

int main ( void )
{
    {
        std::cout << "Test #1" << std::endl;
        Animal giraffe;

        giraffe.makeSound();
        std::cout << "Type: " << giraffe.getType() << std::endl;
    }
    {
        std::cout << "Test #2" <<  std::endl;
        Cat cat;
        cat.makeSound();
        std::cout << "Type: " << cat.getType() << std::endl;
    }
    {
        std::cout << "Test #3" <<  std::endl;
        Dog dog;
        dog.makeSound();
        std::cout << "Type: " << dog.getType() << std::endl;
    }
    {
        std::cout << "Test #4" <<  std::endl;
        const Animal* meta = new Animal(); 
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl; 
        std::cout << i->getType() << " " << std::endl; 
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;   
    }
    {
        std::cout << "Test #5" <<  std::endl;
        const WrongAnimal* meta = new WrongAnimal(); 
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl; 
        i->makeSound(); //will output the cat sound!
        meta->makeSound();
        delete meta;
        delete i;
    }
    {
        std::cout << "Test #6" << std::endl;
        Animal* animal = new Cat();
        animal->makeSound(); // Outputs "Cat sound"
        std::cout << "Type: " << animal->getType() << std::endl; // Outputs "Cat"
        delete animal;
    }
    {
        std::cout << "Test #7" << std::endl;
        Animal* animal = new Dog();
        animal->makeSound(); // Outputs "Dog sound"
        std::cout << "Type: " << animal->getType() << std::endl; // Outputs "Dog"
        delete animal;
    }
    {
        std::cout << "Test #8" << std::endl;
        WrongAnimal* wrongAnimal = new WrongCat();
        wrongAnimal->makeSound(); // Outputs "Wrong cat sound"
        std::cout << "Type: " << wrongAnimal->getType() << std::endl; // Outputs "WrongCat"
        delete wrongAnimal;
    }
    return 0;
}