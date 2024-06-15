/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:51:38 by sofia             #+#    #+#             */
/*   Updated: 2024/06/11 12:51:58 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>
#include <map>
#include <exception>
# include <iostream>


class RPN {

  private:
    RPN ( RPN const &other );
    RPN &operator=( RPN const &other);

    std::stack<double> _nums;
    std::string _expr;
    int _res;
    
    bool isOperator ( std::string const &op ) const;
    bool isTerm ( std::string const &op ) const;
    void performOperation ( std::string const &op );

    static double add ( double a, double b );
    static double sub ( double a, double b );
    static double mlt ( double a, double b );
    static double div ( double a, double b );

  public:
    RPN ( std::string expression );
    ~RPN ();

    void setResult ( double d );
    double getResult () const;

    class execErrorException: public std::exception {
      public:
        virtual const char *what() const throw() {
          return "Invalid expression";
        }
    };
};