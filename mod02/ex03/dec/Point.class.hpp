#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

#include "Fixed.class.hpp"

class Point {
    public:
        Point( void );
        Point( const float x, const float y);
        Point( const Point &other);
        ~Point( void );
        Point& operator = (const Point &other);
        Fixed getX( void ) const;
        Fixed getY( void ) const;
    private:
        Fixed const x;
        Fixed const y;



};

#endif