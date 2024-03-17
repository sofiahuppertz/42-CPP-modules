#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <iostream>

class Zombie
{
  public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	//Setter
	void setName(std::string name);

	//Getter
	std::string getName(void) const;

	// Member function
	void anounce(void) const;

  private:
	std::string _name;
};

#endif