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
        Fixed& operator = (const Fixed &other);
        ~Fixed ( void );
        int getRawBits ( void ) const;
        void setRawBits ( const int raw );
        float toFloat ( void ) const;
        int toInt ( void ) const;

    private:
        int fixed_point;
        static const int fractionalBits = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& object);

#endif