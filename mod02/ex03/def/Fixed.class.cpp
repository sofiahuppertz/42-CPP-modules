
#include "../dec/Fixed.class.hpp"


//Destructor


Fixed:: ~Fixed ( void ) {
    return;
}


// Constructors 


Fixed:: Fixed ( void ) {
    this->fixed_point = 0;
    return;
}

Fixed:: Fixed ( const int n ) {
    this->fixed_point = n << this->fractionalBits;
    return;
}

Fixed:: Fixed ( const float n ) {
    this->fixed_point = roundf(n * (1 << this->fractionalBits));
    return;
}

Fixed:: Fixed ( const Fixed &other): fixed_point(other.fixed_point) {return;}


// Setter and getter


int Fixed::getRawBits ( void ) const 
{
    return this->fixed_point;
}

void Fixed::setRawBits ( const int raw )
{
    this->fixed_point = raw;
    return;
}


// Conversion functions


float Fixed::toFloat ( void ) const
{
    return (float)this->fixed_point / (1 << this->fractionalBits);
}

int Fixed::toInt ( void ) const
{
    return this->fixed_point >> this->fractionalBits;
}


// Assignment operator


Fixed& Fixed:: operator = ( const Fixed &other)
{
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}


// Arithmetic operators


Fixed Fixed::operator+(const Fixed& other) const {
    int rawBits = this->fixed_point + other.fixed_point;
    Fixed result;
    result.setRawBits(rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    int rawBits = this->fixed_point - other.fixed_point;
    Fixed result;
    result.setRawBits(rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    int rawBits = this->fixed_point * other.fixed_point;
    Fixed result;
    result.setRawBits(rawBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.fixed_point != 0) {
        int rawBits = this->fixed_point / other.fixed_point;
        Fixed result;
        result.setRawBits(rawBits);
        return result;
    } else {
        throw std::invalid_argument("Division by zero");
    }
}


// Increment and decrement operators


Fixed& Fixed::operator++() {
    this->fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->fixed_point++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->fixed_point--;
    return temp;
}


// Comparison operators


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


// Static member functions


Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    return (a > b ) ? a : b; 
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
    return (a > b ) ? a : b; 
}


// Non-member functions


// Insertion operator
std::ostream& operator << (std::ostream& os, const Fixed& object) 
{
    os << object.toFloat();
    return os;
}