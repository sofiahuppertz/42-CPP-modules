#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <iostream>

class Zombie {

    public:
        Zombie( void );
        ~Zombie( void );

        void setName( std::string name );
        std::string getName (void ) const;
        void anounce( void ) const;

    private:
        std::string _name;
        

};

#endif