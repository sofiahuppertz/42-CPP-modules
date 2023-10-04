
#include "PhoneBook.class/PhoneBook.class.hpp"

int main ( void )
{
    PhoneBook phonebook;
    std::string input;

    while (1)
    {
        std::cout << "Enter ADD, SEARCH or EXIT: ";
        std::getline(std::cin, input);
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
            break;
        }
        else 
        {
            std::cout << "Let's discard this input" << std::endl;
        }  
    }
    return 0;
}