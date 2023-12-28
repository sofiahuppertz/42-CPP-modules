
#include "dec/Bsp.hpp"

int    main(void)
{
    {
        Point a(-7, 4);
        Point b(-5, -2);
        Point c(4, 4);
        Point point(-3, 2);

        std::cout << ((bsp(a, b, c, point)) ? "True" : "False") << std::endl;
    }
    {
        Point a(-7, 4);
        Point b(-5, -2);
        Point c(4, 4);
        Point point(-8, -2);

        std::cout << ((bsp(a, b, c, point)) ? "True" : "False") << std::endl;
    }
    {
        Point a(-7, 4);
        Point b(-5, -2);
        Point c(4, 4);
        Point point(4, 4);

        std::cout << ((bsp(a, b, c, point)) ? "True" : "False") << std::endl;
    }

}