#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <stdexcept>
#include <string>


class Date {
    public :
        Date (std::string date);
        Date ( Date const & src);
        ~Date (void);

        Date & operator=( Date const & rhs);
        bool isInRange( Date const & start, const Date &end ) const;

    private :
        int _year;
        int _month;
        int _day;

        void _stringToDate (std::string &date);
        int _dateToNum ( void ) const ;
        bool _isDateExist ( void ) const;
        static std::string  _trimDate(const std::string& str);
};


# endif