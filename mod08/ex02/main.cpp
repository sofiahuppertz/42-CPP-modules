#include "dec/Mutantstack.hpp"
#include <iostream>
#include <list>

// ANSI color codes
const std::string green("\033[0;32m");
const std::string blue("\033[0;34m");
const std::string reset("\033[0m");

int main()
{
    MutantStack<int> mstack;
    std::list<int> mlist;

    // Push elements
    mstack.push(5);
    mstack.push(17);
    mlist.push_back(5);
    mlist.push_back(17);

    // Print top/last element
    std::cout << green << "Stack top: " << mstack.top() << reset << std::endl;
    std::cout << blue << "List back: " << mlist.back() << reset << std::endl;

    // Pop elements
    mstack.pop();
    mlist.pop_back();

    // Print size
    std::cout << green << "Stack size: " << mstack.size() << reset << std::endl;
    std::cout << blue << "List size: " << mlist.size() << reset << std::endl;

    // Push more elements
    mstack.push(3); mstack.push(5); mstack.push(737); mstack.push(0);
    mlist.push_back(3); mlist.push_back(5); mlist.push_back(737); mlist.push_back(0);

    // Iterate and print elements
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << green << "Stack: " << *it << reset << std::endl;
        ++it;
    }

    std::list<int>::iterator list_it = mlist.begin();
    std::list<int>::iterator lite = mlist.end();
    while (list_it != lite) {
        std::cout << blue << "List: " << *list_it << reset << std::endl;
        ++list_it;
    }

    // Copy to a new stack
    std::stack<int> s(mstack);

    return 0;
}