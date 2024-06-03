#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "dec/easyfind.hpp"
#include "dec/ANSIColors.hpp"




void simulate_searching() {
    for (int i = 0; i < 3; ++i) {
        std::cout << ".";
        std::cout.flush();
       usleep(400000);
    }
    std::cout << std::endl;
}

bool find_in_arg(std::string arg, char c) {
    return arg.find(c) != std::string::npos;
}

int main(int argc, char* argv[])
{

    // Check user input
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [number]" << std::endl;
        return 1;
    }
    
    int searchValue;
    try
    { 
        std::string arg = argv[1];
        if (find_in_arg(arg, '.') ||  find_in_arg(arg, 'f') || find_in_arg(arg, 'F')) {
            throw InvalidArgumentException();
        }
        searchValue = std::atoi(argv[1]);
        if (argv[1][0] == '\0' || (searchValue == 0 && argv[1][0] != '0')) {
            throw InvalidArgumentException();
        }
    } catch (std::exception &e) {
        std::cerr << ANSIColors::BACKGROUND_RED << "\tException Caught:" << ANSIColors::RESET << ANSIColors::RED <<  " " << e.what() << std::endl;
        return 1;
    }

    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);
    myvector.push_back(40);

    std::cout << ANSIColors::BACKGROUND_MAGENTA << " 🔍 We are first going to call easyfind() with a vector. 👀 " << ANSIColors::RESET << std::endl;

    std::cout << ANSIColors::MAGENTA << "\tValues inside the vector: ";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout  << ANSIColors::RESET << std::endl;


    std::cout << ANSIColors::MAGENTA << "\tSearching in vector container ." ;
    simulate_searching();


    try {
        std::vector<int>::iterator it = easyfind(myvector, searchValue);
        std::cout << ANSIColors::MAGENTA << "\tFound value " << *it << "!🎉 At possition: " << std::distance(myvector.begin(), it) <<  ANSIColors::RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << "\t"<< ANSIColors::RED << e.what() << ANSIColors::RESET<< std::endl;
    }

    std::deque<int> mydeque;
    for (int i = 0; i < 10; i++)
    {
        mydeque.push_front(i);
    }

    std::cout <<  std::endl << ANSIColors::BACKGROUND_BLUE << "🔍 Now we are going to call easyfind() with a deque. 👀" << ANSIColors::RESET << std::endl;

    std::cout << ANSIColors::BLUE << "\tValues inside the deque: ";
    for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "\tSearching in Deque container ." << ANSIColors::RESET;
    simulate_searching();



    try {
        std::deque<int>::iterator it = easyfind(mydeque, searchValue);
        std::cout << ANSIColors::BLUE << "\tFound value " << *it << "!🎂 At possition " << std::distance(mydeque.begin(), it) << ANSIColors::RESET << std::endl;
    } catch (std::exception &e)
    {
        std::cout << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << "\t"<< ANSIColors::RED << e.what() << ANSIColors::RESET<< std::endl;
    }


    std::list<int> mylist;
    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        int randomValue = 1 + std::rand() % 100;
        mylist.push_back(randomValue);
    }

    std::cout <<  std::endl << ANSIColors::BACKGROUND_GREEN << "🔍 At last, we are going to call easyfind() with a list. 👀" << ANSIColors::RESET << std::endl;

    std::cout << ANSIColors::GREEN << "\tList values: ";
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << "\tSearching in List container ." << ANSIColors::RESET;;
    simulate_searching();

    try {
        std::list<int>::iterator it = easyfind(mylist, searchValue);
        std::cout << ANSIColors::GREEN << "Found value " << *it << " at possition " << std::distance(mylist.begin(), it) << ANSIColors::RESET << std::endl;
    } catch (std::exception &e)
    {
        std::cout << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << "\t"<< ANSIColors::RED << e.what() << ANSIColors::RESET<< std::endl;
    }
    return 0;

}

