#ifndef WRONGCAT_CLASS_H
#define WRONGCAT_CLASS_H

#include "WrongAnimal.class.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(WrongCat const & src);
        ~WrongCat(void);
        WrongCat & operator=(WrongCat const & rhs);
        void makeSound(void) const;
};

#endif