
#include "../dec/Dog.class.hpp"

Dog::Dog ( void ): Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    brain = new Brain();
    return;
}

Dog::Dog (const Dog &other) : Animal( other )
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = other._type;
    if (other.brain) {
        brain = new Brain(*other.brain);
    } else {
        brain = NULL;
    }
    return;
}

Dog::~Dog ( void )
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
    return;
}

Dog &Dog::operator=( const Dog &other ) 
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        if (other.brain)
        {
            this->brain = new Brain(*other.brain);
        } else {
            brain = NULL;
        }
        this->_type = other._type;
    }
    return *this;
}

void Dog::makeSound ( void ) const
{
    std::cout << "Wouf! Wouf! Wouf!" << std::endl;
    return;
}

Brain *Dog::getBrain( void ) const
{
    return this->brain;
}

void Dog::setIdea( std::string idea, int index )
{
    brain->ideas[index] = idea;
    return;
}

std::string Dog::getIdea( int index ) const
{
    return brain->ideas[index];
}