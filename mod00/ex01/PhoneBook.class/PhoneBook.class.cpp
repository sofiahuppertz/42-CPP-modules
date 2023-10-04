
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void) {
    return;
}

PhoneBook::~PhoneBook( void ) {
    return;
}

void PhoneBook::addContact( void) {

    int index;
    std::string  tmp_input;

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

std::string  PhoneBook::promptInfo(std::string prompt ) {

    std::string tmp_input;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, tmp_input))
            exit (1);
        if (tmp_input == "EXIT")
            exit (0);
        else if (tmp_input.length() == 0)
            continue;
        else if (tmp_input.length() > 10)
            tmp_input = tmp_input.substr(0, 9) + '.';
        else if (tmp_input.length() < 10)
            tmp_input.insert(0, std::string(10 - tmp_input.length(), ' '));
        break;
    }

    return tmp_input;
}

void PhoneBook::displayContactList ( void )
{
    int i;
    int input;
    std::string inputr_str;

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
            break;
        std::cout << "Index: ";
        if (!std::getline(std::cin, inputr_str))
            exit (1);
        if (inputr_str == "EXIT")
            exit (0);
        try {
            input = std::stoi(inputr_str);
        } catch (std::exception &e) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            continue;
        }
        if (input < 1 || input > PhoneBook::__nbContacts) {
            std::cout << "Invalid input. Please enter a valid number" << std::endl;
            continue;
        }
        this->contacts[input - 1].displayContact();
        break;
    }
    return;
}

int PhoneBook::__nbContacts = 0; //number of contacts in the phonebook (0 - 8)
int PhoneBook::__oldestContact = 0; //index  of the oldest contact (0 - 7)