#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap( const DiamondTrap &other);
        ~DiamondTrap(void);

        DiamondTrap &operator=(const DiamondTrap &other);

        void setName(std::string name);
        std::string getName(void) const;

        void attack(std::string const & target);
        void whoAmI(void);
    private:
        std::string _name;
};



#endif