#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <iostream>
# include <string>


class ClapTrap {
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap( const ClapTrap &other);
        ~ClapTrap(void);

        ClapTrap &operator=(const ClapTrap &other);

        //Getters and setters
        virtual void setName(std::string name);
        void setHitPoints(int hitPoints);
        void setEnergyPoints(int energyPoints);
        void setAttackDamage(int attackDamage);

        virtual std::string getName(void) const;
        virtual int getHitPoints(void) const;
        virtual int getEnergyPoints(void) const;
        virtual int getAttackDamage(void) const;

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        //Helper function
        bool checkStatus (void) const;

    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};

#endif