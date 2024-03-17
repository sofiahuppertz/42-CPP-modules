
#include "PhoneBook.class/PhoneBook.class.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";

		//Read input
		if (!(std::getline(std::cin, input)))
		{
			std::cout << "End of input received, exiting program" << std::endl;
			return (0);
		}

		// Classify and handle input
		if (input == "ADD")
		{
			phonebook.addContact();
		}
		else if (input == "SEARCH")
		{
			phonebook.displayContactList();
		}
		else if (input == "EXIT")
		{
			return (0);
		}
		else
		{
			std::cout << "Let's discard this input" << std::endl;
		}
	}
	return (0);
}