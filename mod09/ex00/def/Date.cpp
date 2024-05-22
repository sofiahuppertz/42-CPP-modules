#include "../dec/Date.hpp"

Date::Date (std::string date) {
    _stringToDate(date);
}

Date::Date ( Date const & src ): _year(src._year), _month(src._month), _day(src._day) {
    return;
}

Date::~Date (void) {
    return;
}

Date & Date::operator=( Date const & other) {

    if (this != &other)
    {
        _year = other._year;
        _month = other._month;
        _day = other._day;
    }
    return *this;
}

std::string Date::_trimDate(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

       
void Date::_stringToDate (std::string &date) {
    
    date = _trimDate(date);
    if (date.size() != 10)
    {
        throw std::logic_error("bad input => " + date );
    }
    for (int i = 0; i < 10; i++)
    {
        if ( i == 4 || i == 7 )
        {
            if (date[i] != '-')
                throw std::logic_error("bad input => " + date );
        }
        else
        {
            if (!isdigit(date[i]))
                throw std::logic_error("bad input => " + date );
        }
    }
    _year = std::stoi(date.substr(0, 4));
    _month = std::stoi(date.substr(5, 2));
    _day = std::stoi(date.substr(8, 2));
    if (!_isDateExist())
    {
        throw std::logic_error("bad input => " + date );
    }
}


bool Date::_isDateExist ( void ) const {

    if (_year < 0 || _month < 1 || _month > 12 || _day < 1)
    {
        return false;
    }
    
    int maxDay;
    switch (_month)
    {
        case 2:
            maxDay = 28;
            if (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0))
                maxDay = 29;
            break;
        case 4: case 6: case 9: case 11: 
            maxDay = 30;
            break;
        default:
            maxDay = 31;
            break;
    } 
    return _day <= maxDay;

}
        
int Date::_dateToNum ( void ) const {

    return _year * 10000 + _month * 100 + _day;
}


bool Date::isInRange( Date const & start, const Date &end ) const
{
    if (_dateToNum() >= start._dateToNum() && _dateToNum() <= end._dateToNum())
        return true;
    return false;
}
