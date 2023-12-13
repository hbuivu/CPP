#include "Account.hpp"
#include <chrono>
#include <ctime>

Account::Account(int initial_deposit)
	:	_amount(initial_deposit)
{
	std::cout << 
}

Account::~Account()
{
}

static int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

static int	Account::getTotalAmount()
{
	return (_totalAmount);
}

static int	Account:: getNbDeposits()
{
	return (_nbDeposits);
}

static int	Account::getNbWithdrawals()
{
	return (_nbWithdrawals);
}
static void	Account::displayAccountsInfos()
{
	//index, amount, deposits, withdrawls
}

static void	_displayTimestamp()
{
	time_t		t = time(nullptr);
	struct tm	*tm = localtime(&t);

	int day = tm ->tm_mday;
	int	month = tm->tm_mon + 1;
	int	year = tm->tm_year + 1900;
	int hour = tm->tm_hour;
	int	minutes = tm->tm_min;
	int seconds = tm->tm_sec;

	std::cout << "[" << year << month << day << "_" << hour << minutes << seconds << "] ";
}