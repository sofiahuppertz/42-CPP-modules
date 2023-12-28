
#include "../dec/Fixed.class.hpp"


// Constructors 

Fixed:: Fixed ( void )
{
    this->fixed_point = 0;
    return;
}

Fixed:: Fixed ( const int n )
{
    this->fixed_point = n << this->fractionalBits;
    return;
}

Fixed:: Fixed ( const float n )
{
    this->fixed_point = roundf(n * (1 << this->fractionalBits));
    return;
}

Fixed:: Fixed ( const Fixed &other): fixed_point(other.fixed_point)
{
    return;
}


// Destructor

Fixed:: ~Fixed ( void )
{
    return;
}


// Member Functions

int Fixed::getRawBits ( void ) const 
{
    return this->fixed_point;
}

void Fixed::setRawBits ( const int raw )
{
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


// Operator overloading

Fixed& Fixed:: operator = ( const Fixed &other)
{
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Fixed& object) 
{
    os << object.toFloat();
    return os;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() != 0) {
        return Fixed(this->toFloat() / other.toFloat());
    } else {
        throw std::invalid_argument("Division by zero");
    }
}

Fixed& Fixed::operator++() {
    this->fixed_point++;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->fixed_point++;
    return temp;
}

// Pre-decrement
Fixed& Fixed::operator--() {
    this->fixed_point--;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    this->fixed_point--;
    return temp;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

Fixed& Fixed::min( Fixed &a, Fixed &b )
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b )
{
    return (a > b ) ? a : b; 
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b )
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b )
{
    return (a > b ) ? a : b; 
}