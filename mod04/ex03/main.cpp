
#include "dec/AMateria.class.hpp"
#include "dec/Character.class.hpp"
#include "dec/Cure.class.hpp"
#include "dec/Ice.class.hpp"
#include "dec/MateriaSource.class.hpp"

int main() 
{
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "Test 1" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "Test 2" << std::endl;
        ICharacter* me = new Character("me");
        AMateria* ice = new Ice();
        AMateria* cure = new Cure();

        me->equip(ice);
        me->equip(cure);
        me->use(0, *me);
        me->use(1, *me);

        
        delete ice;
        delete cure;
        delete me;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "Test 3" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        me->unequip(0);
        me->use(0, *bob);  // This should not do anything because the materia at index 0 has been unequipped
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "Test 4" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");  // This should return nullptr because the source has not learned "cure"
        if (tmp == nullptr) {
            std::cout << "Source has not learned cure" << std::endl;
        }
        delete me;
        delete src;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "Test 5" << std::endl;
        ICharacter* me = new Character("me");
        AMateria* ice = new Ice();
        AMateria* cure = new Cure();
        me->equip(ice);
        me->equip(cure);
        me->use(0, *me);
        me->use(1, *me);
        me->use(2, *me);  // This should not do anything because there is no materia at index 2
        for (int i = 0; i < 4; i++) {
            me->unequip(i); 
        }
        delete ice;
        delete cure;
        delete me;
    }
    return 0;

}