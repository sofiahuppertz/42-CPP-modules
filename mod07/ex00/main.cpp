#include "dec/Templates.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

//Vectors only for testing purposes...


//Function to check if a string is a valid number
bool is_valid_number(std::string str)
{
    if (str.empty())
        return false;
    if (str.length() == 1 and not isdigit(str[0]))
        return false;

    int i = 0;
    if (str[0] == '+' or str[0] == '-')
        i = 1;
    for (; i < int(str.length()); i++)
    {
        if (not isdigit(str[i]))
            return false;
    }
    return true;
}

int main (void)
{


    int a = 1;
    int b = 2;
    //char c = 'a';
    min(a, b);

    try {
        // Prompt for a sentence or word
        std::cout << ANSIColors::BRIGHT_BACKGROUND_GREEN << "Enter a sentence or a word:" << ANSIColors::RESET << " ";
        std::string inputLine;
        std::getline(std::cin, inputLine);
        if (inputLine.empty())
            throw std::exception();

        std::istringstream iss(inputLine);
        std::vector<std::string> words;
        std::string word;

        // Split the input into words
        while (iss >> word)
        {
            words.push_back(word);
        }

        // Calculate the total length of all words
        int totalLength = 0;
        for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
            totalLength += it->length();

        // Copy all words into a single array
        char allWords[totalLength];
        int index = 0;
        for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); it++)
        {
            std::copy(it->begin(), it->end(), allWords + index);
            index += it->length();
        }

        std::cout << std::endl;
        printListInfo(allWords, totalLength);

        iss.str("");
        iss.clear();

        // Prompt for a list of numbers
        std::cout << std::endl << ANSIColors::BRIGHT_BACKGROUND_GREEN << "Enter a list of integers separated by spaces:" << ANSIColors::RESET << " ";
        std::getline(std::cin, inputLine);
        if (inputLine.empty())
            throw std::exception();
        iss.str(inputLine);

        std::vector<int> numbers;
        std::string str;
        int number;

        // Parse the numbers and add them to a vector
        while (iss >> str)
        {
            if (not is_valid_number(str))
                throw std::exception();

            std::stringstream ss(str);
            ss >> number;
            numbers.push_back(number);
        }

        // Copy the numbers into an array
        int numNumbers = numbers.size();
        int numberArray[numNumbers];
        std::copy(numbers.begin(), numbers.end(), numberArray);

        std::cout << std::endl;
        printListInfo(numberArray, numNumbers);
    }
    catch (std::exception &e)
    {
        std::cerr << ANSIColors::BRIGHT_BACKGROUND_RED << "Invalid input" << ANSIColors::RESET << std::endl;
    }
}


//int main( void )
//{
//    int a = 2;
//    int b = 3;
//    ::swap( a, b );
//    std::cout << "a = " << a << ", b = " << b << std::endl;
//    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//    std::string c = "chaine1";
//    std::string d = "chaine2";
//    ::swap(c, d);
//    std::cout << "c = " << c << ", d = " << d << std::endl;
//    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//    return 0;
//}