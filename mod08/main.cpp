#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "dec/easyfind.hpp"

class InvalidArgumentException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "Invalid argument. Please provide a valid integer.";
    }
};

void simulate_searching() {
    for (int i = 0; i < 3; ++i) {
        std::cout << ".";
        std::cout.flush();
       usleep(400000);
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [number]" << std::endl;
        return 1;
    }

    std::cout << "Searching in vector container ." ;
    simulate_searching();

    int searchValue;
    try {
        searchValue = std::atoi(argv[1]);
        if (argv[1][0] == '\0' || (searchValue == 0 && argv[1][0] != '0')) {
            throw InvalidArgumentException();
        }
    } catch (...) {
        std::cerr << InvalidArgumentException().what() << std::endl;
        return 1;
    }

    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);
    myvector.push_back(40);

    try {
        std::vector<int>::iterator it = easyfind(myvector, searchValue);
        std::cout << "\033[34mFound value " << *it << " at possition " << std::distance(myvector.begin(), it) <<"\033[0m" << std::endl;
    } catch (std::exception& e) {
        std::cout << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "Searching in Deque container .";
    simulate_searching();

    std::deque<int> mydeque;
    for (int i = 0; i < 50; i++)
    {
        mydeque.push_front(i);
    }

    try {
        std::deque<int>::iterator it = easyfind(mydeque, searchValue);
        std::cout << "\033[34mFound value " << *it << " at possition " << std::distance(mydeque.begin(), it) <<"\033[0m" << std::endl;
    } catch (std::exception &e)
    {
        std::cout << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }


    std::list<int> mylist;
    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        int randomValue = 1 + std::rand() % 100;
        mylist.push_back(randomValue);
    }

    std::cout << "\033[0;32m" << "List values: ";
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << "\033[0m";

    std::cout << "Searching in List container .";
    simulate_searching();

    try {
        std::list<int>::iterator it = easyfind(mylist, searchValue);
        std::cout << "\033[34mFound value " << *it << " at possition " << std::distance(mylist.begin(), it) <<"\033[0m" << std::endl;
    } catch (std::exception &e)
    {
        std::cout << "\033[35m" << e.what() << "\033[0m" << std::endl;
    }
    return 0;

}

