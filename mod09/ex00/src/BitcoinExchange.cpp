/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:23:08 by sofia             #+#    #+#             */
/*   Updated: 2024/06/10 16:50:54 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::processInputFile(std::string filename)
{
  std::ifstream file(filename);

  // Check if file is open
  if (!file.is_open())
  {
    throw std::runtime_error("Could not open file");
  }

  // Skip header
  std::string header;
  std::getline(file, header);

  // Read file line by line
  std::string line;
  while (std::getline(file, line))
  {
    try
    {

      std::istringstream iss(line);
      std::string newDate;
      std::string newNumStr;
      double newNum;
      double price_for_date;

      getline(iss, newDate, '|');
      parseDate(newDate);
      getline(iss, newNumStr);
      parseNumber(newNumStr);
      std::stringstream ss(newNumStr);
      ss >> newNum;

      price_for_date = priceForDate(newDate);
      std::cout << "\t" << FGRN(newDate) << FGRN("\t=>\t") << FGRN(newNum) << FGRN("\t=\t") << SUNDL(FGRN(price_for_date * newNum)) << std::endl;
    }
    catch (std::exception &e)
    {
      std::cerr << BRED(FWHI("Error:\t")) << BRED(FWHI(" ")) << BRED(FWHI(e.what())) << std::endl;
    }
  }
}

std::map<std::string, double> BitcoinExchange::loadDB(std::string filename, char delimiter)
{

  std::map<std::string, double> dataset;
  std::ifstream file(filename);

  // Check if file is open
  if (!file.is_open())
  {
    throw std::runtime_error("Could not open file");
  }

  // Skip header
  std::string header;
  std::getline(file, header);

  // Read file line by line
  std::string line;
  while (std::getline(file, line))
  {
    // Convert line to stream
    std::istringstream iss(line);

    // Parse line
    std::string date;
    double value;
    if (!(getline(iss, date, delimiter) && (iss >> value)))
    {
      throw std::runtime_error("Could not parse line");
    }
    // Add line to map
    dataset[date] = value;
  }
  file.close();

  return dataset;
}

void BitcoinExchange::parseNumber(std::string &num) const
{
  num = Date::trimDate(num);
  for (unsigned int i = 0; i < num.length() - 1; i++)
  {
    if (num[0] != '-' && num[i] != '.' && !std::isdigit(num[i]))
      throw BitcoinExchange::notANumber();
  }

  double number;
  std::stringstream ss(num);
  ss >> number;
  if (!number || number <= 0)
    throw BitcoinExchange::negativeNumber();
  else if (number >= 1000)
    throw BitcoinExchange::tooLargeNumber();
}

void BitcoinExchange::parseDate(std::string &dateStr) const {

  dateStr = Date::trimDate(dateStr);
  Date date(dateStr);
  // Check date is between the beginning of the DB and today
  if (!date.isInRange(Date("2009-03-01"), Date(Date::getToday())))
    throw Date::dateException(date);
}

double BitcoinExchange::priceForDate(std::string date) {
  std::map<std::string, double>::iterator it = bitcoinPrices.find(date);

  if (it == bitcoinPrices.end())
  {
    it = bitcoinPrices.upper_bound(date);
    it--;
  }
  return it->second;
}

BitcoinExchange::BitcoinExchange(std::string database) : bitcoinPrices(loadDB(database, ',')) 
{}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
  *this = other;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
  bitcoinPrices = other.bitcoinPrices;
  return *this;
}
