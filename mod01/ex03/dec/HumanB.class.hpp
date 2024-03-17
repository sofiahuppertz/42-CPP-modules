#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H

# include "Weapon.class.hpp"

class HumanB
{
  public:
	// Default constructor
	HumanB(std::string name);
	~HumanB(void);

	// Setter
	void setWeapon(Weapon &weapon);

	// Member function
	void attack(void) const;

  private:
	std::string _name;
	Weapon *_weapon;
};

#endif