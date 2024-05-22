#include "../dec/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
    std::string database = "static/data.csv";
    bitcoinPrices = loadFile(database, ',');

}

BitcoinExchange::BitcoinExchange( std::string filename )
{
    bitcoinPrices = loadFile(filename, ',');
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange( void )
{
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
    if (this != &rhs)
    {
        bitcoinPrices = rhs.bitcoinPrices;
    }
    return *this;
}

std::map<std::string, double> BitcoinExchange::loadFile( std::string filename, char delimiter ) {

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
        std::istringstream  iss(line);

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

void BitcoinExchange::printBitcoinPrices( unsigned int begin, unsigned int last ) const
{
    if (begin > last)
    {
        throw std::logic_error("begin > last");
    }
    std::map<std::string, double>::const_iterator it = bitcoinPrices.begin();
    for (unsigned int i = 0; i < last && it != bitcoinPrices.end(); i++)
    {
        if (i >= begin)
            std::cout << it->first << " : " << it->second << std::endl;
        it++;
    }
}

void BitcoinExchange::processInputFile( std::string filename )
{
    std::map<std::string, double> dateAndValues;
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
        try {

            std::istringstream  iss(line);

            std::string newDate;
            double number;
            // Parse line
            getline(iss, newDate, '|') && (iss >> number);
            // Check date is in format YYYY-MM-DD
            Date date(newDate);
            if (!date.isInRange(Date("2009-03-01"), Date("2024-05-22")))
            {
                throw std::logic_error("date => " + newDate);
            }
            // Check number is within range
            if (!number || number < 0)
            {
                throw std::logic_error("not a positive number");
            }
            else if ( number > 1000)
            {
                throw std::logic_error("too large number");
            }
            // compute the rate * number and print it
            double price = priceForDate(newDate);
            std::cout << newDate << " => " << number << " = " << price * number << std::endl;

        } catch (std::exception & e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

double BitcoinExchange::priceForDate( std::string date )
{
    std::map<std::string, double>::iterator it = bitcoinPrices.upper_bound(date);
    if (it == bitcoinPrices.end())
    {
        throw std::logic_error("date not found");
    }
    return it->second;
}

