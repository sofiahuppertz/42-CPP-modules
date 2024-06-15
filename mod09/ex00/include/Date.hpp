/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:34:59 by sofia             #+#    #+#             */
/*   Updated: 2024/06/10 15:03:15 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <exception>
#include <iostream>
#include <string>

class Date {
  private:
    Date &operator=(Date const &rhs);
    Date(Date const &src);

    void _stringToDate();
    int _dateToNum() const;
    bool _isValidDate() const;

    const std::string _date;
    int _year;
    int _month;
    int _day;

  public:
    Date(std::string date);
    ~Date();

    bool isInRange(Date const &start, const Date &end) const;
    std::string getDate() const;

    static std::string trimDate(const std::string &str);
    static std::string getToday();

    class dateException : public std::exception
    {
      public:
        dateException(const Date &dateObj) : _msg("bad input => " + dateObj.getDate()) {}
        virtual const char *what() const throw()
        {
          return (_msg.c_str());
        }
        virtual ~dateException() _NOEXCEPT {}

      private:
        const std::string _msg;
    };

};
