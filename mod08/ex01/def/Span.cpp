#include "../dec/Span.hpp"

Span::Span( void ): storage() {

}

Span::Span( unsigned int N ): storage() {
    storage.reserve(N);
}

Span::Span ( const Span & other ): storage(other.storage) {
}

Span::~Span ( void ) {
}


Span &Span::operator=( const Span &other ) {

    if ( this != &other ) {
        storage = other.storage;
    }
    return *this;
}

void Span::addNumber ( int n ) {

    if ( storage.size() == storage.capacity()) {
        
        throw std::logic_error("Storage is full 🔒");
    } else {
       
        storage.insert(std::upper_bound(storage.begin(), storage.end(), n), n);
    }
}    

void Span::addNumber ( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {

    if ( storage.size() + std::distance(begin, end) > storage.capacity()) {
        throw std::logic_error("Storage is full 🔒");
    } else {
        storage.insert(storage.end(), begin, end);
        std::sort(storage.begin(), storage.end());
    }
}

unsigned int Span::shortestSpan ( void ) const {


    // Make sure there are at least 2 elements in the storage
    if ( storage.size() < 2 ) {
        throw std::logic_error("Not enough elements to calculate span.");
    }

    // Calculate the shortest span
    int shortestSpan = std::abs(storage[0] - storage[1]);
    for ( size_t i = 1; i < storage.size(); i++) {
        shortestSpan = std::min(shortestSpan, std::abs(storage[i] - storage[i+1]));
    }

    return static_cast<unsigned int>(shortestSpan);
}


unsigned int Span::longestSpan ( void ) const {
    
    // Make sure there are at least 2 elements in the storage
    if ( storage.size() < 2 ) {
        throw std::logic_error("Not enough elements to calculate span.");
    }
        
    return static_cast<unsigned int>(storage.back() - storage.front());
}


// My functions (getters)

unsigned int Span::getCapacity( void ) const {
    return storage.capacity();
}

unsigned int Span::getSize( void ) const {
    return storage.size();
}

void Span::print( unsigned int last_index ) const
{
    std::string colors[] = {ANSIColors::RED, ANSIColors::GREEN, ANSIColors::YELLOW, ANSIColors::BLUE, ANSIColors::MAGENTA, ANSIColors::CYAN, ANSIColors::WHITE};
    
    for ( size_t i = 0; i < last_index && i <= storage.size() - 1; i++) 
    {
        std::cout << colors[i % colors->length()] << storage[i] << ANSIColors::RESET << " ";
    }
    std::cout  << std::endl;
}