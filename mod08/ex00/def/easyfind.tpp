#include "../dec/easyfind.hpp"

class NotFoundException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Element Not Found.";
        };
};

class InvalidArgumentException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "Not an integer.";
    }
};

template <typename T>
typename T::iterator easyfind( T &container, int value)
{
    // Check if the container's value type is an integer
    try 
    {
        assert(typeid(typename T::value_type) == typeid(int));
    }
    catch (std::exception &e) 
    {
        std::cerr << ANSIColors::BACKGROUND_RED << "Exception caught:"  << ANSIColors::RESET << ANSIColors::RED << "Not an Integer" <<  ANSIColors::RESET << std::endl;
        return container.end();
    }

    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw NotFoundException();
    }

    return it;
}