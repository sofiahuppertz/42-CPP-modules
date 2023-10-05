#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <iostream>

class Zombie {

    public:
        Zombie( std::string name );
        ~Zombie( void );

        void anounce( void ) const;

    private:
        std::string _name;
        

};

#endif