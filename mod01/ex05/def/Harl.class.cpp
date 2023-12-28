
#include "../dec/Harl.class.hpp"

Harl::Harl( void )
{
    std::cout << "Harl created" << std::endl;
    return;
}

Harl::~Harl ( void )
{
    std::cout << "Harl destroyed" << std::endl;
    return;
}

void Harl::_debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
    return;
}

void Harl::_info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return;
}

void Harl::_warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    return;
}

void Harl::_error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return;
}

void    Harl::complain( std::string level)
{
    void (Harl::*f[4])(void);
    std::string  levels[4];

    f[0] = &Harl::_debug;
    f[1] = &Harl::_info;
    f[2] = &Harl::_warning;
    f[3] = &Harl::_error;

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*f[i])();
    }
    return;
}

