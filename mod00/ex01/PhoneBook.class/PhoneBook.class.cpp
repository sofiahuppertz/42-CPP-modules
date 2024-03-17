
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::addContact(void)
{
	int	index;

	std::string tmp_input;
	if (PhoneBook::__nbContacts < 8)
	{
		index = PhoneBook::__nbContacts;
		PhoneBook::__nbContacts += 1;
	}
	else
	{
		index = __oldestContact;
		PhoneBook::__oldestContact = (PhoneBook::__oldestContact + 1) % 8;
	}
	tmp_input = promptInfo("First name: ");
	this->contacts[index].setFirstName(tmp_input);
	tmp_input = promptInfo("Last name: ");
	this->contacts[index].setLastName(tmp_input);
	tmp_input = promptInfo("Nickname: ");
	this->contacts[index].setNickname(tmp_input);
	tmp_input = promptInfo("Phone number: ");
	this->contacts[index].setPhoneNumber(tmp_input);
	tmp_input = promptInfo("Darkest secret: ");
	this->contacts[index].setDarkestSecret(tmp_input);
}

static bool	isOnlyWhiteSpace(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

std::string PhoneBook::promptInfo(std::string prompt)
{
	std::string tmp_input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, tmp_input))
			exit(EXIT_FAILURE);
		if (tmp_input == "EXIT")
			exit(EXIT_SUCCESS);
		else if (tmp_input.length() == 0 || isOnlyWhiteSpace(tmp_input))
			continue ;
		else if (tmp_input.length() > 10)
			tmp_input = tmp_input.substr(0, 9) + '.';
		else if (tmp_input.length() < 10)
			tmp_input.insert(0, std::string(10 - tmp_input.length(), ' '));
		break ;
	}
	return (tmp_input);
}

void PhoneBook::displayContactList(void)
{
	int			i;
	int			index;
	const char	*input_cstr;

	std::string input_str;
	while (1)
	{
		for (i = 0; i < PhoneBook::__nbContacts; i++)
		{
			std::cout << i + 1 << std::string(9, ' ') << "|";
			std::cout << this->contacts[i].getFirstName() << "|";
			std::cout << this->contacts[i].getLastName() << "|";
			std::cout << this->contacts[i].getNickname() << std::endl;
		}
		if (i == 0)
			break ;
		std::cout << "Index: ";
		if (!std::getline(std::cin, input_str))
			exit(EXIT_FAILURE);
		if (input_str == "EXIT")
			exit(EXIT_SUCCESS);
		try
		{
			input_cstr = input_str.c_str();
			index = atoi(input_cstr);
		}
		catch (std::exception &e)
		{
			std::cout << "Invalid index. Please enter a valid number." << std::endl;
			continue ;
		}
		if (index < 1 || index > PhoneBook::__nbContacts)
		{
			std::cout << "Invalid index. Please enter a valid number" << std::endl;
			continue ;
		}
		this->contacts[index - 1].displayContact();
		break ;
	}
	return ;
}

int PhoneBook::__nbContacts = 0;    //number of contacts in the phonebook (0- 8)
int PhoneBook::__oldestContact = 0; //index  of the oldest contact (0 - 7)