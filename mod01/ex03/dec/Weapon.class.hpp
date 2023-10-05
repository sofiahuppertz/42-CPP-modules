#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H

#include <iostream>

class Weapon {
    
    public:
        Weapon( std::string type);
        ~Weapon( void );
        void setType( std::string type);
        std::string getType( void ) const;

    private:
        std::string _type;

};

#endif