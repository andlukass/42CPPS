#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	this->_nbDeposits = 0;
	this->_nbDeposits = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account( void ){

}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ){
	return 1;
}

int	Account::getTotalAmount( void ){
	return 1;
}

int	Account::getNbDeposits( void ){
	return 1;
}

int	Account::getNbWithdrawals( void ){
	return 1;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << \
	";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << \
	";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << ";deposit:" << deposit << \
	";amount:" << this->_amount + deposit << ";nb_deposits:" << 1 << std::endl;

	this->_nbDeposits++;
	this->_amount += deposit;

	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	if (this->_amount - withdrawal < 0) {
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << \
		";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	} else {
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << \
		";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << \
		";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << 1 << std::endl;

		this->_nbWithdrawals++;
		this->_amount -= withdrawal;

		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return true;
	}
}

int	Account::checkAmount( void ) const {
	return 1;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << \
	";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
	<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
	<< std::setw(2) << std::localtime(&result)->tm_mday
	<< "_"
	<< std::setw(2) << std::localtime(&result)->tm_hour
	<< std::setw(2) << std::localtime(&result)->tm_min
	<< std::setw(2) << std::localtime(&result)->tm_sec
	<< "] ";
}