
#include <iostream>

template <class T>
Array<T>::Array( void ): array(nullptr), _size(0){
// array = nullptr is the same than array = new T[0];
}

template <class T>
Array<T>::Array ( unsigned int n ): _size(n) {
    array = new T[n];
}

template <class T>
Array<T>::Array ( Array const & src): _size(src._size){
    array = new T[_size];
    copyElements(src.array, array, _size);
}

template <class T>
Array<T>::~Array( void ) {
    delete [] array;
}

template <class T>
void Array<T>::copyElements( const T *src, T *dst, unsigned int _size ) {

    for (unsigned int i = 0; i < _size; i++)
        dst[i] = src[i];
}

template <class T>
T & Array<T>::operator[](unsigned int idx ) {
    if (idx >= static_cast<unsigned int>(_size)) {
        throw std::out_of_range("Index out of range");
    }
    return array[idx];
}

template <class T>
const T & Array<T>::operator[](unsigned int idx ) const {
    if (idx >= static_cast<unsigned int>(_size)){
        throw std::out_of_range("Index out of range");
    }
    return array[idx];
}

template <class T>
Array<T> & Array<T>::operator=( Array const & other) {
    if (this != &other) {
        delete [] array;
        _size = other._size;
        array = new T[_size];
        copyElements(other.array, array, _size);
    }
}

template <class T>
unsigned int Array<T>::size ( void ) const {
    return _size;
}