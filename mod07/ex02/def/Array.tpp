
#include <iostream>

template <class T>
Array<T>::Array( void ):  _size(0) {
    array = new T[0];
}

template <class T>
Array<T>::Array ( unsigned int n ): _size(n) {
    array = new T[n];
}

template <class T>
Array<T>::Array ( Array const & src): _size(src._size){
    array = new T[size()];
    copyElements(src.array, array);
}

template <class T>
Array<T>::~Array( void ) {
    delete [] array;
}

template <class T>
void Array<T>::copyElements( const T *src, T *dst ) {

    for (unsigned int i = 0; i < size(); i++)
        dst[i] = src[i];
}

template <class T>
T & Array<T>::operator[](unsigned int idx ) {
    if (idx >= static_cast<unsigned int>(size())) {
        throw std::out_of_range("Index out of range");
    }
    return array[idx];
}

template <class T>
const T & Array<T>::operator[](unsigned int idx ) const {
    if (idx >= static_cast<unsigned int>(size())){
        throw std::out_of_range("Index out of range");
    }
    return array[idx];
}

template <class T>
Array<T> & Array<T>::operator=( Array const & other) {
    if (this != &other) {
        delete [] array;
        _size = other.size();
        array = new T[size()];
        copyElements(other.array, array);
    }
    return *this;
}

template <class T>
unsigned int Array<T>::size ( void ) const {
    return _size;
}

// For testing purposes

template<class T>
void Array<T>::printArray( void ) const
{
    std::string Colors[] = {ANSIColors::BLACK, ANSIColors::RED, ANSIColors::GREEN, ANSIColors::YELLOW, ANSIColors::BLUE, ANSIColors::MAGENTA, ANSIColors::CYAN, ANSIColors::WHITE};

    std::cout << "\t";
    for (unsigned int i = 0; i < size(); i++)
        std::cout << Colors[rand() % 8] << array[i] << " ";
    std::cout << std::endl;

}

template<class T>
T *Array<T>::getArray( void ) const {
    return array;
}