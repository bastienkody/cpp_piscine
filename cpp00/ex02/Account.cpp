// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Dec 01 19:43:15 2023                      //
//                Last update : Wed Dec 03 14:54:06 2023                      //
//                Made by : bguillau  <bguillau@student.42.fr>                //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <ctime>
#include <iostream>

/*	static member init	*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*	getters on static memb	*/
int	Account::getNbAccounts(void) {return (_nbAccounts);}
int	Account::getTotalAmount(void) {return (_totalAmount);}
int	Account::getNbDeposits(void) {return (_totalNbDeposits);}
int	Account::getNbWithdrawals(void) {return (_totalNbWithdrawals);}

/*	timestamp, but why static?	*/
void	Account::_displayTimestamp(void)
{
	time_t	now;
	tm		*local_time;
	char	timestamp[20];

	time(&now); 											// since epoch, type time_t
	local_time = localtime(&now);							// epoch converted to local tmz in a tm struct
	strftime(timestamp, 20, "[%Y%m%d_%H%M%S]", local_time); // formatted
	std::cout << timestamp;									// has to be printed (void type)
}

/*	global display (only static members)	*/
// I use the getters on static memb but i guess not needed ; lets try else way if it compiles. 
void	Account::displayAccountsInfos(void)
{
	const char	*words[4] = {" accounts:", ";total:", ";deposits:", ";withdrawals:"};

	_displayTimestamp();
	std::cout << words[0] << getNbAccounts();
	std::cout << words[1] << getTotalAmount();
	std::cout << words[2] << getNbDeposits();
	std::cout << words[3] << getNbWithdrawals();
	std::cout << std::endl;

}

/*	solo object display	*/
void	Account::displayStatus(void) const
{
	const char	*words[4] = {" index:", ";amount:", ";deposits:", ";withdrawals:"};

	_displayTimestamp();
	std::cout << words[0] << this->_accountIndex;
	std::cout << words[1] << this->_amount;
	std::cout << words[2] << this->_nbDeposits;
	std::cout << words[3] << this->_nbWithdrawals;
	std::cout << std::endl;
}

/*	constructors (needed to define default too?)	*/
Account::Account(){}

Account::Account(int initial_deposit)
{
	const char	*words[3] = {" index:", ";amount:", ";created"};

	this->_accountIndex = _nbAccounts;	//set index
	_nbAccounts++;						//add a new account to STATIC var
	this->_amount = initial_deposit;	//initial deposit amount
	_totalAmount += initial_deposit;	//adjust STATIC global bank amount (son passif narvalo de la finance)
	this->_nbDeposits = 0;				//init to 0
	this->_nbWithdrawals = 0;			//init to 0

	_displayTimestamp();
	std::cout << words[0] << this->_accountIndex;
	std::cout << words[1] << this->_amount;
	std::cout << words[2] << std::endl;
}

/*	destructor	*/
Account::~Account()
{
	const char	*words[3] = {" index:", ";amount:", ";closed"};

	_displayTimestamp();
	std::cout << words[0] << this->_accountIndex;
	std::cout << words[1] << this->_amount;
	std::cout << words[2] << std::endl;
}

/*	actions and check	*/
void	Account::makeDeposit(int deposit)
{
	const char	*words[5] = {" index:", ";p_amount:", ";deposit:", ";amount:", ";nb_deposits:"};

	_displayTimestamp();
	std::cout << words[0] << this->_accountIndex;
	std::cout << words[1] << this->_amount;
	std::cout << words[2] << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << words[3] << this->_amount;
	std::cout << words[4] << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	const char	*words[5] = {" index:", ";p_amount:", ";withdrawal:", ";amount:", ";nb_withdrawals:"};

	_displayTimestamp();
	std::cout << words[0] << this->_accountIndex;
	std::cout << words[1] << this->_amount;
	std::cout << words[2];

	this->_amount -= withdrawal;

	if (!this->checkAmount())
	{
		this->_amount += withdrawal;
		std::cout << "refused" << std::endl;
		return (0);
	}

	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	std::cout << withdrawal;
	std::cout << words[3] << this->_amount;
	std::cout << words[4] << this->_nbWithdrawals << std::endl;
	return (1);
}

int		Account::checkAmount(void) const {return (this->_amount >= 0);}
