#include "Account.hpp"
#include <iostream>

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

	std::cout << "_timestamp" << " index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account( void ){

}

Account::~Account( void ){
	std::cout << "_timestamp" << " index:" << this->_accountIndex << \
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
	std::cout << "_timestamp" << " accounts:" << _nbAccounts << \
	";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << \
	";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	std::cout << "_timestamp" << " index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << ";deposit:" << deposit << \
	";amount:" << this->_amount + deposit << ";nb_deposits:" << 1 << std::endl;

	this->_nbDeposits++;
	this->_amount += deposit;

	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	if (this->_amount - withdrawal < 0) {
		std::cout << "_timestamp" << " index:" << this->_accountIndex << \
		";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	} else {
		std::cout << "_timestamp" << " index:" << this->_accountIndex << \
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
	std::cout << "_timestamp" << " index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << \
	";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	// [19920104_091532]
}