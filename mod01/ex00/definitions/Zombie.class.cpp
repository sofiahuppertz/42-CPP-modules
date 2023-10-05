
#include "../declarations/Zombie.class.hpp"

Zombie::Zombie( std::string name ) : _name(name) {
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