#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed {
    
    public:
        Fixed ( void );
        Fixed ( const Fixed &other);
        Fixed& operator=(const Fixed &other);
        ~Fixed ( void );
        int getRawBits ( void ) const;
        void setRawBits ( const int raw );

    private:
        int fixed_point;
        static const int _frac = 8;
};

#endif