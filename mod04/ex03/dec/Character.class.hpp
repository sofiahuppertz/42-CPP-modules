#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H


#include "ICharacter.class.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
    private:
        const std::string _name;
        int _count;

    public:
        Character( void );
        Character(std::string name);
        Character(const Character &other);
        ~Character();
        
        Character &operator=(const Character &other);

        virtual std::string const &getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);

};
#endif