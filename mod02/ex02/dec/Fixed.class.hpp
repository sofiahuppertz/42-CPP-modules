#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class Fixed {
    
    public:
        Fixed ( void );
        Fixed ( const int n );
        Fixed ( const float n );
        Fixed ( const Fixed &other);
        ~Fixed ( void );
        
        // Operators
        Fixed& operator = (const Fixed &other);
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        
        // Member Functions
        float toFloat ( void ) const;
        void setRawBits ( const int raw );
        int toInt ( void ) const;
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