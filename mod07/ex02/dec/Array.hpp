#ifndef ARRAY_HPP
#define ARRAY_HPP


template <class T>
class Array {

    public:
        Array( void );
        Array ( unsigned int n );
        Array ( Array const & src);
        ~Array( void );

        // Overload of the subscript operator
        T & operator[]( unsigned int idx );
        const T & operator[]( unsigned int idx ) const;

        // Overload of the assignment operator
        Array & operator=( Array const & other );

        unsigned int size ( void ) const;
        void copyElements( const T *src, T *dst, unsigned int size );

    private:
        T *array;
        unsigned int _size;
};

#include "../def/Array.tpp"

# endif