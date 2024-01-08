
#include "../dec/Cat.class.hpp"

Cat::Cat ( void ): AAnimal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    brain = new Brain();
    return;
}

Cat::Cat (const Cat &other) : AAnimal( other )
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = other._type;
    if (other.brain) 
    {
        brain = new Brain(*other.brain);
    } else {
        brain = NULL;
    }
}

Cat::~Cat ( void )
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
    return;
}

Cat &Cat::operator=(const Cat &other) 
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        if (other.brain) {
            this->brain = new Brain(*other.brain);
        } else {
            brain = NULL;
        }
        this->_type = other._type;
    }
    return *this;
}

void Cat::makeSound ( void ) const
{
    std::cout << "Miau miau miau" << std::endl;
    return;
}

Brain *Cat::getBrain( void ) const
{
    return this->brain;
}

void Cat::setIdea( std::string idea, int index )
{
    brain->ideas[index] = idea;
}

std::string Cat::getIdea( int index ) const
{
    return brain->ideas[index];
}