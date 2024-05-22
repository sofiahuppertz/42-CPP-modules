#include "dec/BitcoinExchange.hpp"

int main ( void )
{
    BitcoinExchange pricesForDate("static/data.csv");
    pricesForDate.printBitcoinPrices(1600, 1610);
    pricesForDate.processInputFile("static/input.csv");

    return 0;
}