/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:02:11 by sofia             #+#    #+#             */
/*   Updated: 2024/06/11 12:46:43 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>


RPN::RPN ( std::string expression ) : _expr(expression) {
  
  std::istringstream ss(_expr);
  std::string elem;  

  while (ss >> elem) {
    // Check it's a valid number or operator, if not display error and stop
    if (isOperator(elem))
    {
      performOperation(elem);
    }
    else if (isTerm(elem))
    {
      _nums.push(std::atoi(elem.c_str()));
    }
    else
      throw RPN::execErrorException();

  }
  if (_nums.size() != 1)
    throw RPN::execErrorException();
  setResult(_nums.top());
  _nums.pop();
}

void RPN::performOperation ( std::string const &op ) {
  
  double a, b;
  std::map <std::string, double(*)(double, double)> operations;
  operations["+"] = &RPN::add;
  operations["-"] = &RPN::sub;
  operations["*"] = &RPN::mlt;
  operations["/"] = &RPN::div;

  if (_nums.size() < 2)
    throw RPN::execErrorException();
  b = _nums.top();
  _nums.pop();
  a = _nums.top();
  _nums.pop();

  if (operations.find(op) != operations.end())
    _nums.push(operations[op](a, b));
}

bool RPN::isOperator ( std::string const &op ) const {

  char operators[4] = {'+', '-', '/', '*'};

  if (op.size() != 1)
    return false;
  char c = static_cast<char>(op[0]);
  for ( int i = 0; i < 4; i++)
  {
    if (c == operators[i])
      return true;
  }
  return false;
}

bool RPN::isTerm ( std::string const &op ) const {

  if (op.size() != 1)
    return false;
  return std::isdigit(op[0]);
}


void RPN::setResult ( double d ) {
  _res = d;
}

double RPN::getResult () const {
  return _res;
}

double RPN::add ( double a, double b ) { return a + b; }
double RPN::sub ( double a, double b ) { return a - b; }
double RPN::mlt ( double a, double b ) { return a * b; }
double RPN::div ( double a, double b ) { return a / b; }

RPN::RPN ( RPN const &other ) {
  (void)other;
}

RPN &RPN::operator=( RPN const &other) {
  (void)other;
  return *this;
}

RPN::~RPN () {}

