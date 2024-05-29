
#include "dec/Base.class.hpp"
#include "dec/A.class.hpp"
#include "dec/B.class.hpp"
#include "dec/C.class.hpp"

#include <iostream>
#include <ctime>
#include <sstream>
#include <exception>


// ANSI COLOR CODES
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BACKGROUND_RED  "\033[41m"
#define BACKGROUND_GREEN  "\033[42m"
#define BACKGROUND_BLUE  "\033[44m"

Base *generate ( void )
{
    int random = std::rand() % 3;
    if (random == 0)
        return new A;
    if (random == 1)
        return new B;
    return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << BACKGROUND_BLUE << "A" << RESET;
    else if (dynamic_cast<B*>(p))
        std::cout << BACKGROUND_GREEN << "B" << RESET;
    else if (dynamic_cast<C*>(p))
        std::cout << BACKGROUND_RED << "C" << RESET;
    return;
}

void identify(Base& p)
{
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << BLUE << "A" << RESET;
        (void)a;
    }
    catch(const std::exception &e){}
    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << GREEN << "B" <<  RESET;
        (void)b;
    }
    catch(const std::exception &e){}
    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << RED << "C" << RESET;
        (void)c;
    }
    catch(const std::exception &e){}
}

int main ( void)
{

    std::cout << CYAN << "Enter a random number: " << RESET;
    std::string input;
    std::getline(std::cin, input);
    try {
        double seed;
        std::istringstream ss(input);
        ss >> seed;
        if (ss.fail() || !ss.eof())
            throw std::exception();
        std::srand(static_cast<unsigned int>(seed * time(0)));
        for (int i = 0; i < 9; ++i) {
            Base* obj = generate();
            std::cout << "Object " << i + 1 << ": ";
            identify(obj);
            std::cout << " ";
            identify(*obj);
            std::cout << std::endl;
            delete obj;
        }
    }
    catch (std::exception &e) {
        std::cout << "Invalid number" << std::endl;
        return 1;
    }

    return 0;
}