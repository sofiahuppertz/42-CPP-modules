
#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

#include "ClapTrap.class.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap( const ScavTrap &other);
        ~ScavTrap(void);

        ScavTrap &operator=(const ScavTrap &other);

        void attack(std::string const & target);
        void guardGate(void);
};

#endif