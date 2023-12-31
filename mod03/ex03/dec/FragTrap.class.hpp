#ifndef FLAGTRAP_CLASS_H
# define FLAGTRAP_CLASS_H

#include "ClapTrap.class.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap( const FragTrap &other);
        ~FragTrap(void);

        FragTrap &operator=(const FragTrap &other);

        void highFivesGuys(void);
};

#endif