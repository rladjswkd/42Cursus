#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void){}

Account::Account(int initial_deposit){
    _accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void){
    return (_nbAccounts);
}

int	Account::getTotalAmount(void){
    return (_totalAmount);
}

int	Account::getNbDeposits(void){
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
        << ";total:" << getTotalAmount()
        << ";deposits:" << getNbDeposits()
        << ";withdrawals:" << getNbWithdrawals()
        << std::endl;
}

void	Account::makeDeposit(int deposit){
    _displayTimestamp();
    _amount += deposit;
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount - deposit
        << ";deposit:" << deposit
        << ";amount:" << _amount
        << ";nb_deposits:" << ++_nbDeposits
        << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:";
    if (_amount >= withdrawal){
        _amount -= withdrawal;
        std::cout << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << ++_nbWithdrawals
            << std::endl;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    } else {
        std::cout << "refused" << std::endl;
        return (false);
    }
}

int		Account::checkAmount(void) const{
    return (1);
}

void	Account::displayStatus(void) const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";deposits:" << _nbDeposits
        << ";withdrawals:" << _nbWithdrawals
        << std::endl;
}

void	Account::_displayTimestamp(void){
    time_t  now = time(0);
    tm      *tmp = localtime(&now);

    std::cout << "["
        << tmp->tm_year + 1900
        << std::setw(2) << std::setfill('0') << tmp->tm_mon
        << std::setw(2) << std::setfill('0') << tmp->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << tmp->tm_hour
        << std::setw(2) << std::setfill('0') << tmp->tm_min
        << std::setw(2) << std::setfill('0') << tmp->tm_sec
        << "] ";
}