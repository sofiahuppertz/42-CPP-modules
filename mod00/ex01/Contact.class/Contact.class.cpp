
#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::setFirstName(std::string str)
{
	this->_first_name = str;
	return ;
}

void Contact::setLastName(std::string str)
{
	this->_last_name = str;
	return ;
}

void Contact::setNickname(std::string str)
{
	this->_nickname = str;
	return ;
}

void Contact::setPhoneNumber(std::string str)
{
	this->_phone_number = str;
	return ;
}

void Contact::setDarkestSecret(std::string str)
{
	this->_darkest_secret = str;
	return ;
}

std::string Contact::getFirstName(void) const
{
	return (this->_first_name);
}

std::string Contact::getLastName(void) const
{
	return (this->_last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}

void Contact::displayContact(void)
{
	std::cout << "First name: " << this->getFirstName() << std::endl;
	std::cout << "Last name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNickname() << std::endl;
	std::cout << "Phone number: " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->getDarkestSecret() << std::endl;
	return ;
}
