#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H

# include "Weapon.class.hpp"

class HumanA
{
  public:
	// Initialization constructor
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	// Member function
	void attack(void) const;

  private:
	std::string _name;
	Weapon &_weapon;
};

#endif
