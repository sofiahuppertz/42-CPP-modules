
#include "../dec/Brain.class.hpp"

Brain::Brain(void) {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain ( const Brain &other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain copy assignement operator called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    return *this;
}