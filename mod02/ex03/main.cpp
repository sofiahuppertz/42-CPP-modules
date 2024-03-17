
#include "dec/Bsp.hpp"
#include <climits>
int main(void)
{
    std::cout << "Welcome to triangle_point!" << std::endl;
    std::cout << "This program checks whether a point P is inside" << std::endl;
    std::cout << "a triangle ABC or not." << std::endl;
    while (true)
    {
        Point points[4];
        char point_names[4] = {'A', 'B', 'C', 'P'};
        for (int i = 0; i < 4; i++)
        {
            int x, y;
            std::cout << "Enter the x and y coordinates of point " << point_names[i] << ": " << std::endl;
            std::cout << "x: ";
            std::cin >> x;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
                i--;
                continue;
            }
            std::cout << "y: ";
            std::cin >> y;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
                i--;
                continue;
            }
            points[i] = Point(x, y);
        }
        std::cout << ((bsp(points[0], points[1], points[2], points[3])) ? "True" : "False") << std::endl;
        std::cout << "Do you want to try again? (y/n): ";
        char answer;
        std::cin >> answer;
        if (answer == 'n')
            break;
    }
    return 0;
}

