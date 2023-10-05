
#include "../dec/Zombie.class.hpp"

Zombie::Zombie ( void )
{
    std::cout << "Zombie created." << std::endl;
    return;
}

Zombie::~Zombie( void ) {
    std::cout << this->_name << " is dead." << std::endl;
    return;
}

void Zombie::anounce( void ) const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
} 

void Zombie::setName( std::string name )
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " created." << std::endl;
    return;
}

std::string Zombie::getName( void ) const
{
    return this->_name;
}