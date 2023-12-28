#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class Fixed {
    public:
        // Constructors and destructor
        Fixed ( void );
        Fixed ( const int n );
        Fixed ( const float n );
        Fixed ( const Fixed &other);
        ~Fixed ( void );

        // Assignment operator
        Fixed& operator = (const Fixed &other);

        // Arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Increment and decrement operators
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        // Comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;

        // Conversion functions
        float toFloat ( void ) const;
        int toInt ( void ) const;

        // Getter and setter for raw bits
        void setRawBits ( const int raw );
        int getRawBits ( void ) const;

        // Static member Functions
        static Fixed& min( Fixed& a, Fixed& b );
        static Fixed& max( Fixed& a, Fixed& b );
        static const Fixed& min( const Fixed& a, const Fixed& b );
        static const Fixed& max( const Fixed& a, const Fixed& b );

    private:
        int fixed_point;
        static const int fractionalBits = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& object);

#endif