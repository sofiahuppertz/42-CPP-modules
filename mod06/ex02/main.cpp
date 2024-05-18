
#include "dec/Base.class.hpp"
#include "dec/A.class.hpp"
#include "dec/B.class.hpp"
#include "dec/C.class.hpp"

#include <iostream>

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
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    return;
}

void identify(Base& p)
{
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(const std::exception &e){}
    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(const std::exception &e){}
    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(const std::exception &e){}
}

int main ( void )
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 10; ++i) {
        Base* obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
    }
    return 0;
}