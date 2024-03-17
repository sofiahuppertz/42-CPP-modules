
#include "dec/HumanA.class.hpp"
#include "dec/HumanB.class.hpp"
#include "dec/Weapon.class.hpp"

// Having a pointer to a Weapon instance allows to initialize the HumanB instance without a weapon.
// This is not possible with HumanA because it has a reference to a Weapon instance.
// In both cases the weapon is "independent" from the Human instance.
// The difference is that in HumanA the weapon instance has to be "fixed" and in HumanB it can be changed.

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Weapon poisonousRope = Weapon("poisonous rope");
		HumanB jim("Jim");

		jim.attack();
		// This has no effect because jim instance doesn't have a weapon yet.
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		jim.setWeapon(poisonousRope);
		jim.attack();
	}
	return (0);
}