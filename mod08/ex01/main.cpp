#include "dec/Span.hpp"
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <vector>


bool isValidInt ( const std::string &input )
{
  if (input.empty()) {
    return false;
  }
  unsigned int i = 0;
  if (input[i] == '-' || input[i] == '+') {
    i++;
  }
  for ( ; i < input.size(); i++) {
    if ( !std::isdigit(input[i]) ) {
      return false;
    }
  }
  double num;
  std::istringstream ss(input);
  ss >> num;

  return (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max());
}

bool isValidUnsignedInt ( const std::string &input )
{

    for ( size_t i = 0; i < input.size(); i++) {
        if ( !std::isdigit(input[i]) ) {
            return false;
        }
    }
    double num;
    std::istringstream ss(input);
    ss >> num;

    return (num >= std::numeric_limits<unsigned int>::min() && num <= std::numeric_limits<unsigned int>::max());
}

int main ( void )
{

  unsigned int N;
  std::string input;
  
  std::cout << ANSIColors::BACKGROUND_CYAN << "Enter a size N:" << ANSIColors::RESET << " ";  
  std::getline(std::cin, input);

  if (!isValidUnsignedInt(input)) {
    std::cerr << ANSIColors::BACKGROUND_RED << "Wrong input!💩" << ANSIColors::RESET << std::endl;
    return 1;
  }
  N = static_cast<unsigned int>(std::atoi(input.c_str()));

  Span span(N);
  std::cout << std::endl << ANSIColors::BACKGROUND_GREEN << "\tSpan created! ⭐" << ANSIColors::RESET << std::endl << std::endl;
  std::cout << ANSIColors::CYAN << "\tSpan capacity " << span.getCapacity() << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::CYAN << "\tSpan size: " << span.getSize() << ANSIColors::RESET << std::endl;
  
  std::cout << std::endl << ANSIColors::BACKGROUND_CYAN << "Enter an integer or a list of integers separated by a space:" << ANSIColors::RESET << " ";
  std::getline(std::cin, input);
  std::istringstream ss(input);
  
  std::vector<int> numbers;
  while (ss >> input) {
    if (!isValidInt(input)) {
      std::cerr << std::endl << ANSIColors::BACKGROUND_RED << "\tWrong input!💩" << ANSIColors::RESET << std::endl;
      return 1;
    }
    numbers.push_back(std::atoi(input.c_str()));
  }
  try {
    span.addNumber(numbers.begin(), numbers.end());
    std::cout << std::endl << ANSIColors::BACKGROUND_GREEN << "\tNumbers added successfully! ⭐" << ANSIColors::RESET << std::endl << std::endl;
    std::cout << ANSIColors::CYAN << "\tSpan capacity: " << span.getCapacity() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tSpan size: " << span.getSize() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tShortest span: " << span.shortestSpan() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tLongest span: " << span.longestSpan() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tSpan content (first 10 elements): " << ANSIColors::RESET;
    span.print(static_cast<unsigned int>(10));
  }
  catch (std::exception &e)
  {
    std::cerr << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << " " << ANSIColors::RED << e.what() << ANSIColors::RESET << std::endl;
  }

  std::cout << std::endl << ANSIColors::BACKGROUND_CYAN << "Enter how many numbers you want to add:" << ANSIColors::RESET << " ";
  std::getline(std::cin, input);
  try{
    if (!isValidUnsignedInt(input)) {
      std::cerr <<  std::endl << ANSIColors::BACKGROUND_RED << "\tWrong input!💩" << ANSIColors::RESET << std::endl;
      return 1;
    }
    N = static_cast<unsigned int>(std::atoi(input.c_str()));
    for (unsigned int i = 0; i < N ; i++)
    {
      span.addNumber(42);
    }
    std::cout << std::endl << ANSIColors::BACKGROUND_GREEN << "\tNumbers added successfully! ⭐" << ANSIColors::RESET << std::endl << std::endl;
    std::cout << ANSIColors::CYAN << "\tSpan capacity: " << span.getCapacity() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tSpan size: " << span.getSize() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tShortest span: " << span.shortestSpan() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tLongest span: " << span.longestSpan() << ANSIColors::RESET << std::endl;
    std::cout << ANSIColors::CYAN << "\tSpan content (first 10 elements): " << ANSIColors::RESET;
    span.print(static_cast<unsigned int>(10));
  }
  catch (std::exception &e)
  {
    std::cerr << ANSIColors::BACKGROUND_RED << "\tException caught:" << ANSIColors::RESET << " " << ANSIColors::RED << e.what() << ANSIColors::RESET << std::endl;
  }
  std::cout << ANSIColors::BACKGROUND_MAGENTA << std::endl << "Bye! If you liked this main, you can put me outstanding. 🐣" << ANSIColors::RESET << std::endl;


  return 0;
   
}