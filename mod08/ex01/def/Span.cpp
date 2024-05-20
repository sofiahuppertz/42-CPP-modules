#include "../dec/Span.hpp"


const std::string blue("\033[0;34m");
const std::string reset("\033[0m");

Span::Span( void ): storageCapacity(0), storage() {

    std::cout << blue << "Default constructor called. Storage capacity = 0" << reset << std::endl;

}

Span::Span( unsigned int N ): storageCapacity(N), storage() {
    storage.reserve(N);
    std::cout << blue << "Constructor called. Storage capacity = " << storageCapacity <<  reset <<std::endl;
}

Span::Span ( const Span & other ): storageCapacity(other.storageCapacity), storage(other.storage) {
    std::cout << blue << "Copy constructor called. Storage capacity = " << storageCapacity << reset << std::endl;
}

Span::~Span ( void ) {
}


Span &Span::operator=( const Span &other ) {

    if ( this != &other ) {
        storageCapacity = other.storageCapacity;
        storage = other.storage;
    }
    return *this;
}

void Span::addNumber ( int n ) {

    if ( storage.size() == storage.capacity()) {
        
        throw std::logic_error("Storage is full");
    } else {
       
        storage.insert(std::upper_bound(storage.begin(), storage.end(), n), n);
    }
}    

void Span::addNumber ( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {

    if ( storage.size() + std::distance(begin, end) > storage.capacity()) {
        throw std::logic_error("Storage is full");
    } else {
        storage.insert(storage.end(), begin, end);
        std::sort(storage.begin(), storage.end());
    }
}

unsigned int Span::shortestSpan ( void ) const {

    int shortestSpan = std::abs(storage[0] - storage[1]);

    // Make sure there are at least 2 elements in the storage
    if ( storage.size() < 2 ) {
        throw std::logic_error("Not enough elements to calculate span");
    }

    // Calculate the shortest span
    for ( size_t i = 1; i < storageCapacity - 1; i++) {
        shortestSpan = std::min(shortestSpan, std::abs(storage[i] - storage[i+1]));
    }

    return static_cast<unsigned int>(shortestSpan);
}


unsigned int Span::longestSpan ( void ) const {
    
    // Make sure there are at least 2 elements in the storage
    if ( storage.size() < 2 ) {
        throw std::logic_error("Not enough elements to calculate span");
    }
        
    return static_cast<unsigned int>(storage.back() - storage.front());
}