
#include "Account.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

int        Account::_nbAccounts = 0;
int        Account::_totalAmount = 0;
int        Account::_totalNbDeposits = 0;
int        Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit) 
{
    Account::_displayTimestamp();
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    return;
}


Account::~Account( void )
{
    Account::_displayTimestamp();
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    return;
}

int        Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int       Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int        Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int        Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void        Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
    return;
}

void    Account::makeDeposit( int deposit)
{
    Account::_displayTimestamp();
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount;" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
    return;
}

void   Account::_displayTimestamp( void )
{
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    std::cout << std::put_time(localTime, "[%Y%m%d_%H%M%S] ");

    return;
}

bool Account::makeWithdrawal ( int withdrawal ) 
{
    Account::_displayTimestamp();
    if (this->checkAmount() <= withdrawal)
    {
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
        return 0;
    }
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return 1;
}

int       Account::checkAmount( void ) const
{
    return this->_amount;
}

void    Account::displayStatus ( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
    return;
}