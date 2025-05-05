/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:32:21 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/05/05 12:18:29 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
    Account::_accountIndex = _nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    Account::_amount = initial_deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";created" << std::endl;
}

Account::~Account( void ){
    _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" << std::endl;
}

void Account::_displayTimestamp( void ){
    time_t        current_time;
    struct tm    *local_time;

    current_time = time (0);
    local_time = localtime(&current_time);
    std::cout << "[" << local_time->tm_year + 1900 << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1 << std::setfill('0') << std::setw(2) << local_time->tm_mday << "_" << std::setfill('0') << std::setw(2) << local_time->tm_hour << std::setfill('0') << std::setw(2) << local_time->tm_min << std::setfill('0') << std::setw(2) << local_time->tm_sec << "]";
}

int Account::getNbAccounts( void ){
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
    return Account::_totalNbDeposits;
}

int Account:: getNbWithdrawals( void ){
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << " account:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/* ⬇️ Funzioni per il singolo account ⬇️ */

void Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";deposits:" << Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ){
    int p_amount = Account::_amount;
    Account::_amount+= deposit;
    Account::_nbDeposits++;
    Account::_totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << Account::_amount << ";nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    int p_amount = Account::_amount;
    if (Account::_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << " index:" << Account::_accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << Account::_amount << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
        return (0);
    }
    else
    {
        std::cout << " index:" << Account::_accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << "refused" << std::endl;
        return (1);
    }
}

int	Account::checkAmount( void ) const{
    return (1);
}

