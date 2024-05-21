#include "dec/Span.hpp"

int main ( void )
{
  // ANSI color codes
  const std::string red("\033[0;31m");
  const std::string green("\033[0;32m");
  const std::string blue("\033[0;34m");
  const std::string reset("\033[0m");

  // Test 1: Add a range of numbers and check the shortest and longest span
  std::cout << "Test 1: Add a range of numbers and check the shortest and longest span" << std::endl;
  std::vector<int> v;
  for ( int i = 0; i < 10000; i++ ) {
    v.push_back(i);
  }

  Span s(10000);
  try {
    s.addNumber(v.begin(), v.end());
    std::cout << green << "Shortest span: " << s.shortestSpan() << reset << std::endl;
    std::cout << green << "Longest span: " << s.longestSpan() << reset << std::endl;
  } catch ( std::exception & e ) {
    std::cout << red << e.what() << reset << std::endl;
  }

  // Test 2: Try to add a number to a full Span
  std::cout << "Test 2: Try to add a number to a full Span" << std::endl;
  try {
    s.addNumber(10000);
  } catch ( std::exception & e ) {
    std::cout << red << "Expected exception: " << e.what() << reset << std::endl;
  }

  // Test 3: Create a Span with a single number and try to calculate the span
  std::cout << "Test 3: Create a Span with a single number and try to calculate the span" << std::endl;
  Span s2(1);
  s2.addNumber(5);
  try {
    std::cout << green << "Shortest span: " << s2.shortestSpan() << reset << std::endl;
  } catch ( std::exception & e ) {
    std::cout << red << "Expected exception: " << e.what() << reset << std::endl;
  }

  // Test 4: Create an empty Span and try to add a range that exceeds its capacity
  std::cout << "Test 4: Create an empty Span and try to add a range that exceeds its capacity" << std::endl;
  Span s3;
  std::vector<int> v2;
  for ( int i = 0; i < 6; i++ ) {
    v2.push_back(i);
  }
  try {
    s3.addNumber(v2.begin(), v2.end());
  } catch ( std::exception & e ) {
    std::cout << red << "Expected exception: " << e.what() << reset << std::endl;
  }

  //Test 5: Create a span with 5 random numbers and check it's spans
  std::cout << "Test 5: Create a span with 5 random numbers and check it's spans" << std::endl;
  Span s4(5);
  s4.addNumber(5);
  s4.addNumber(3);
  s4.addNumber(1);
  s4.addNumber(4);
  s4.addNumber(2);
  std::cout << green << "Shortest span: " << s4.shortestSpan() << reset << std::endl;
  std::cout << green << "Longest span: " << s4.longestSpan() << reset << std::endl;


  // Test 6: Create a Span with a capacity larger than it's size.
  std::cout << "Test 6: Create a Span with a capacity larger than it's size." << std::endl;
  Span s5(10000);
  std::vector<int> v3;
  for ( int i = 0; i < 5000; i++ ) {
    v3.push_back(i * 1.5);
  }
  s5.addNumber(v3.begin(), v3.end());
  std::cout << blue << "Storage capacity: " << s5.getStorageCapacity() << reset << std::endl;
  std::cout << blue << "Storage size: " << s5.getStorageSize() << reset << std::endl;
  std::cout << green << "Shortest span: " << s5.shortestSpan() << reset << std::endl;
  std::cout << green << "Longest span: " << s5.longestSpan() << reset << std::endl;

  return 0;
   
}