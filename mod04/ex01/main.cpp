
#include "dec/Animal.class.hpp"
#include "dec/Brain.class.hpp"
#include "dec/Cat.class.hpp"
#include "dec/Dog.class.hpp"


int main ( void )
{
    {   
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 1--------" << std::endl;
        Animal* animals[4];
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
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 2--------" << std::endl;
        Animal* cat = new Cat();
        Animal* dog = new Dog();

        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
                dog->setIdea("Wouf! Wouf! Wouf!", i);
            else
                dog->setIdea("E = mc^2", i);
        }
        cat = dog;
        std::cout << "Type: " << cat->getType() << std::endl;        
        for (int i = 0; i < 10; i++)
        {
            std::cout << cat->getIdea(i) << std::endl;
        }

    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 3--------" << std::endl;
        Dog* dog1 = new Dog();
        Dog* dog2 = new Dog(*dog1); // Copy constructor test
        dog1->setIdea("Idea 1", 0);
        dog2->setIdea("Idea 2", 0);
        std::cout << "Dog1 Idea: " << dog1->getIdea(0) << std::endl; // Should print "Idea 1"
        std::cout << "Dog2 Idea: " << dog2->getIdea(0) << std::endl; // Should print "Idea 2"
        delete dog1;
        delete dog2;
    }

    {
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 4--------" << std::endl;
        Animal* animal = new Dog();
        animal->makeSound(); // Should print "Woof!"
        delete animal;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 5--------" << std::endl;
        Cat* cat1 = new Cat();
        Cat* cat2 = new Cat();
        cat1->setIdea("Idea 1", 0);
        cat2->setIdea("Idea 2", 0);
        *cat1 = *cat2; // Assignment operator test
        cat1->makeSound(); // Should print "Miau miau miau"
        std::cout << "cat1 Idea: " << cat1->getIdea(0) << std::endl; // Should print "Idea 2"
        delete cat1;
        delete cat2;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 6--------" << std::endl;
        Dog* dog1 = new Dog();
        Dog* dog2 = new Dog();
        dog1->setIdea("Idea 1", 0);
        dog2->setIdea("Idea 2", 0);
        *dog1 = *dog2; // Assignment operator test
        dog1->makeSound(); // Should print "Waouf! Waouf! Waouf!"
        std::cout << "dog1 Idea: " << dog1->getIdea(0) << std::endl; // Should print "Idea 2"
        delete dog1;
        delete dog2;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "-------Test 7--------" << std::endl;
        Animal *Mittens = new Cat();
        Mittens->setIdea("What does the human do with all those boxes they receive?", 0);
        Mittens->setIdea("I should try to fit in one of those boxes", 1);
        Mittens->setIdea("I fit in the box, now what?", 2);

        // Animal *Whiskers = new Cat(*Mittens);
        // It's important we typecast Mittens because it is a pointer to Animal.
        Animal *Whiskers = new Cat(*static_cast<Cat*>(Mittens));
        std::cout << Whiskers->getIdea(0) << std::endl;
        std::cout << Whiskers->getIdea(1) << std::endl;
        std::cout << Whiskers->getIdea(2) << std::endl;
        std::cout << Whiskers->getIdea(3) << std::endl; //This will leave a blank space, because there is no idea at index 3.

        // If you're not sure if Mittens is a pointer to Cat, you can use dynamic_cast ( feature of polymorphism).
        Dog *dog = dynamic_cast<Dog*>(Mittens);
        if (dog)
        {
            Animal *Fido = new Dog(*dog);
            Fido->makeSound();
        }
        else
            std::cout << "Mittens is not a dog" << std::endl;
        //We can pass a pointer to Animal that points to a Cat object to the copy constructor of Animal.
        //This is called "slicing" because only the base class is copied.
        Animal *x = new Animal(*Mittens); 
        x->makeSound();
        std::cout << "Type: " << x->getType() << std::endl;
        //Ideas weren't copied because they are part of the derived class.
        std::cout << "Ideas: " << x->getIdea(0) << x->getIdea(1) << x->getIdea(2) << std::endl;
        std::cout << "This cat is actually not Cat class, it's only Animal. Animal doesn't have a brain so no ideas..." << std::endl;
        delete Mittens;
        delete Whiskers;
        delete x;

    }
    return 0;
}
