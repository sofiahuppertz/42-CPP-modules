
#include "../dec/Fixed.class.hpp"


// Constructors 

Fixed:: Fixed ( void )
{
    this->fixed_point = 0;
    std::cout << "Default Constructor called." << std::endl;
    return;
}

Fixed:: Fixed ( const int n )
{
    std::cout << "Int Constructor called." << std::endl;
    this->fixed_point = n << this->fractionalBits;
    return;
}

Fixed:: Fixed ( const float n )
{
    std::cout << "Float Constructor called." << std::endl;
    this->fixed_point = roundf(n * (1 << this->fractionalBits));
    return;
}

Fixed:: Fixed ( const Fixed &other): fixed_point(other.fixed_point)
{
    std::cout << "Copy Constructor called." << std::endl;
    return;
}


// Destructor

Fixed:: ~Fixed ( void )
{
    std::cout << "Destructor called." << std::endl;
    return;
}


// Member Functions

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

float Fixed::toFloat ( void ) const
{
    return (float)this->fixed_point / (1 << this->fractionalBits);
}

int Fixed::toInt ( void ) const
{
    return this->fixed_point >> this->fractionalBits;
}


// Operators

Fixed& Fixed:: operator = ( const Fixed &other)
{
    std::cout << "Copy Assignement Operator called." << std::endl;
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Fixed& object) 
{
    os << object.toFloat();
    return os;
}