
#include "../dec/Fixed.class.hpp"

Fixed:: Fixed ( void )
{
    this->fixed_point = 0;
    std::cout << "Default Constructor called." << std::endl;
    return;
}

Fixed:: ~Fixed ( void )
{
    std::cout << "Destructor called." << std::endl;
    return;
}

Fixed:: Fixed ( const Fixed &other): fixed_point(other.fixed_point)
{
    std::cout << "Copy Constructor called." << std::endl;
    return;
}

Fixed& Fixed:: operator=( const Fixed &other)
{
    std::cout << "Copy Assignement Operator called." << std::endl;
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}

//Fixed & Fixed:: operator=( const Fixed &other)
//{
//    std::cout << "Copy Assignement Operator called." << std::endl;
//    if (this != &other)
//        this->setRawBits(other.getRawBits());
//    return *this;
//}

int Fixed::getRawBits ( void ) const 
{
    std::cout << "getRawBits member function called." << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits ( const int raw )
{
    std::cout << "setRawBits member function called." << std::endl;
    this->fixed_point = raw;
    return;
}