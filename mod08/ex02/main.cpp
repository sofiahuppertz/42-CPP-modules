#include "dec/Mutantstack.hpp"
#include "dec/ANSIColors.hpp"
#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>

int main()
{

    std::cout << ANSIColors::GREEN << "  __   __  __   __  _______  _______  __    _  _______  _______  _______  _______  _______  ___   _  " << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::GREEN << " |  |_|  ||  | |  ||       ||   _   ||  |  | ||       ||       ||       ||   _   ||       ||   | | | " << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::GREEN << " |       ||  | |  ||_     _||  |_|  ||   |_| ||_     _||  _____||_     _||  |_|  ||       ||   |_| | " << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::GREEN << " |       ||  |_|  |  |   |  |       ||       |  |   |  | |_____   |   |  |       ||       ||      _| " << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::GREEN << " |       ||       |  |   |  |       ||  _    |  |   |  |_____  |  |   |  |       ||      _||     |_  " << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::GREEN << " | ||_|| ||       |  |   |  |   _   || | |   |  |   |   _____| |  |   |  |   _   ||     |_ |    _  | " << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::GREEN << " |_|   |_||_______|  |___|  |__| |__||_|  |__|  |___|  |_______|  |___|  |__| |__||_______||___| |_| 👽" << ANSIColors::RESET << std::endl;


    std::cout << std::endl <<  ANSIColors::GREEN << "Stacking numbers is boring, am I right?" <<  ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::GREEN << "Let's stack some jokes instead! [ Try to answer or type exit to stop the game ]" << ANSIColors::RESET << std::endl;

    MutantStack<std::pair<std::string, std::string> > jokeStack;
    jokeStack.push(std::make_pair("Why don't programmers like nature?", "Because it has too many bugs."));
    jokeStack.push(std::make_pair("How many programmers does it take to change a light bulb?", "None. That's a hardware problem."));
    jokeStack.push(std::make_pair("Why do Java developers wear glasses?","Because they don't C#."));
    jokeStack.push(std::make_pair("Why was the computer cold?", "It left its Windows open."));
    jokeStack.push(std::make_pair("What did the spider do on the computer?", "It made the web!"));
    jokeStack.push(std::make_pair("Why Neil Armstrong didn't get any memory leaks?", "Because space is infinite."));
    
    MutantStack<std::pair<std::string, std::string> >::iterator it = jokeStack.begin();
    MutantStack<std::pair<std::string, std::string> >::iterator ite = jokeStack.end();

    for (; it != ite; ++it)
    {
        std::cout << std::endl << "\t" << ANSIColors::BLUE << it->first << " " << ANSIColors::RESET;

        std::string input;
        std::getline(std::cin, input);
        if (input.empty() || input == "exit")
            break;
        if (input == it->second)
            std::cout << std::endl << ANSIColors::GREEN << "\tCorrect!" << ANSIColors::RESET << std::endl;
        else
            std::cout << std::endl << ANSIColors::RED << "\tIncorrect! The answer is: " << it->second << ANSIColors::RESET << std::endl;
    }
    std::cout << std::endl << "\t" << ANSIColors::BACKGROUND_MAGENTA << "END OF GAME.🎮" << ANSIColors::RESET << std::endl;



    
}