
#include "../dec/Point.class.hpp"

//Destructor

Point:: ~Point ( void ) {
    return;
}


// Constructors

Point:: Point ( void ): x(Fixed(0)), y(Fixed(0)) {
    return;
}

Point:: Point ( const float x, const float y): x(Fixed(x)), y(Fixed(y)) {
    return;
}

Point:: Point ( const Point &other): x(other.x), y(other.y) {
    return;
}


// Assignment operator
// Points are inmutable, but we could have an array of points 
// and we would like to initialize them "twice"
// So we can use the const_cast to remove the constness of the object

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        const_cast<Fixed&>(this->x) = other.x;
        const_cast<Fixed&>(this->y) = other.y;
    }
    return *this;
}

// Getters

Fixed Point::getX( void ) const {
    return this->x;
}

Fixed Point::getY( void ) const {
    return this->y;
}