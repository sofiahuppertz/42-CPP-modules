#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

#include <iostream>
#include <string>

class Animal {
    public:
        Animal ( void );
        Animal ( std::string type );
        Animal (const Animal &other);
        virtual ~Animal ( void );

        Animal &operator=(const Animal &other);
        std::string getType ( void )const;
        virtual void makeSound ( void ) const;

    protected:
        std::string _type;
};

#endif