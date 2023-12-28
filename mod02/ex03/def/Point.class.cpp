
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

Point& Point::operator= (const Point &other) {
    (void)other;
    throw std::logic_error("Assignment not allowed for Point objects");
}

// Getters

Fixed Point::getX( void ) const {
    return this->x;
}

Fixed Point::getY( void ) const {
    return this->y;
}