#ifndef WRONGANIMAL_CLASS_H
# define WRONGANIMAL_CLASS_H

#include <iostream>
#include <string>

class WrongAnimal {
    public:
        WrongAnimal ( void );
        WrongAnimal ( std::string type );
        WrongAnimal (const WrongAnimal &other);
        virtual ~WrongAnimal ( void );

        WrongAnimal &operator=(const WrongAnimal &other);
        std::string getType ( void )const;
        void makeSound ( void ) const;

    protected:
        std::string _type;
};

#endif