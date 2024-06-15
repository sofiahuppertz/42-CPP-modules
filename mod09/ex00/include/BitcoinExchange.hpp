/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:27 by sofia             #+#    #+#             */
/*   Updated: 2024/06/10 15:37:10 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "Date.hpp"
#include "Ansi.hpp"

class BitcoinExchange {

  private:
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);
    std::map<std::string, double> bitcoinPrices;

  public:
    BitcoinExchange(std::string database);
    ~BitcoinExchange();

    std::map<std::string, double> loadDB(std::string filename, char delimiter);
    double priceForDate(std::string date);
    void processInputFile(std::string filename);

    void parseNumber(std::string &num) const;
    void parseDate(std::string &date) const;

    class notANumber : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
          return "Not a number.";
        }
    };

    class negativeNumber : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
          return "Not a positive number.";
        }
    };

    class tooLargeNumber : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
          return "Number is too large.";
        }
    };
};
