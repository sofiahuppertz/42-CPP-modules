#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "../Contact.class/Contact.class.hpp"
# include <cstdlib>
# include <iostream>
# include <stdlib.h>
# include <string>

# define MAX_CONTACTS 8;

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	static int __nbContacts;
	static int __oldestContact;

	void addContact(void);
	std::string promptInfo(std::string prompt);
	void displayContactList(void);

  private:
	Contact contacts[8];
};

#endif