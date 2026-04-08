/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:09:36 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/28 19:51:12 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
};

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
	_nbAccounts--;
};

int	Account::getNbAccounts(void) {
	return _nbAccounts;
};

int	Account::getTotalAmount(void) {
	return _totalAmount;
};

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
};

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
};

int		Account::checkAmount(void) const {
	return this->_amount;
};

void Account::_displayTimestamp(void) {
	time_t	raw = time(&raw);
	struct tm * now = localtime(&raw);
	char timeFormated[19];
	strftime(timeFormated, 19, "[%Y%m%d_%H%M%S] ", now);
	std::cout << timeFormated;
};

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
};

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount()
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
};

void	Account::makeDeposit(int deposit) {
	if (deposit <= 0){
		Account::_displayTimestamp();
		std::cout << "Can't deposit a negative or 0 amount." << std::endl;
	}
	else {
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
		std::cout << ";deposit:" << deposit << ";amount:";
		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
		std::cout << this->checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
	}
};

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	if (withdrawal > this->checkAmount()) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return true;
};
