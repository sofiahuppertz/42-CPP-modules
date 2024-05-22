#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Date.hpp"

class BitcoinExchange {

    public:
        BitcoinExchange( void );
        BitcoinExchange( std::string filename );
        BitcoinExchange( BitcoinExchange const & src );
        ~BitcoinExchange( void );
        BitcoinExchange & operator=( BitcoinExchange const & rhs );

        std::map<std::string, double> loadFile( std::string filename, char delimiter);
        void printBitcoinPrices( unsigned int begin, unsigned int last ) const;
        void processInputFile( std::string filename );
        double priceForDate( std::string date );

    private:
        std::map<std::string, double> bitcoinPrices;

};




#endif
