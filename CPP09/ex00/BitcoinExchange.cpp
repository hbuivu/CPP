#include "BitcoinExchange.hpp"
#include <cstring>
#include <iomanip>

//initialize with overloaded operator<
std::map<std::tm, double, bool(*)(const std::tm&, const std::tm&)> BitcoinExchange::_db(&operator<);
std::tm		BitcoinExchange::_date;
double		BitcoinExchange::_value = 0;
std::string	BitcoinExchange::_line = "";

bool operator < (const std::tm& t1, const std::tm& t2)
{
	return (std::mktime(const_cast<std::tm*>(&t1)) < std::mktime(const_cast<std::tm*>(&t2)));
};

void	BitcoinExchange::parseDatabase()
{
	std::ifstream infile("data.csv"); 
	if (!infile.is_open())
		throw InvalidFileException();
	std::getline(infile, _line);
	if (_line != "date,exchange_rate")
		throw InvalidFileException();
	while (std::getline(infile, _line))
	{
		try
		{
			std::istringstream ss(_line);
			char dash1, dash2, comma;
			double exchangeRate;
			ss	>> _date.tm_year >> dash1 >> _date.tm_mon >> dash2
				>> _date.tm_mday >> comma >> exchangeRate;
			if (ss.fail() || ss.get() != EOF || 
				dash1 != '-' ||dash2 != '-' || comma != ',')
				throw BadInputException();
			else if (exchangeRate < 0)
				throw NegativeNumberException();
			else if (exchangeRate > INT_MAX)
				throw LargeNumberException();
			//adjust year and month to match data requirements in struct
			_date.tm_year -= 1900; //year range starts from 1900
			_date.tm_mon -= 1; //month range 0-11
			if (std::mktime(&_date) == -1)
				throw BadInputException();
			if (_db.find(_date) != _db.end()) //if a copy is found already
				throw DuplicateException();
			_db[_date] = exchangeRate;
		}
		catch(BadInputException &e)
		{
			std::cerr << e.what() << _line << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}

//have a function that checks if container is empty. if it is, return ;

void	BitcoinExchange::parseInput(std::string Input)
{
	std::ifstream infile(Input.c_str());
	if (!infile.is_open())
		throw InvalidFileException();
	std::string _line;
	std::getline(infile, _line);
	if (_line != "date | value")
		throw InvalidFileException();
	while (std::getline(infile, _line))
	{
		try
		{
			//convert std::string _line to a stringstream
			std::istringstream ss(_line);
			char dash1, dash2, pipe; //istringstream ignores leading white spaces
			ss	>> _date.tm_year >> dash1 >> _date.tm_mon >> dash2
				>> _date.tm_mday >> pipe >> _value;
			
			//ss.fail() - if extraction fails
			//ss.get() - if there is still more in the string
			if (ss.fail() || ss.get() != EOF ||
				dash1 != '-' ||dash2 != '-' || pipe != '|')
				throw BadInputException();
			else if (_value < 0)
				throw NegativeNumberException();
			else if (_value > 1000)
				throw LargeNumberException(); 

			//adjust year and month to match data requirements in struct
			_date.tm_year -= 1900; //year range starts from 1900
			_date.tm_mon -= 1; //month range 0-11

			//check if the date is valid;
			if (std::mktime(&_date) == -1)
				throw BadInputException();
			
			//check if date is falls outside of range in data.csv
			if (_date < _db.begin()->first || _db.rbegin()->first < _date) //we switch the statement in the second half because we only defined operator <
				throw DateRangeException();
			if(_db.find(_date) != _db.end())
				printData();
			else
				printClosestDateData();
		}
		catch(BadInputException &e)
		{
			std::cerr << e.what() << _line << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	
	}
}

void	BitcoinExchange::printData()
{	
	double	finalValue = _value * _db[_date]; //we do this bc we modify _date to get the correctly printed year and month
	std::cout	<< (_date.tm_year + 1900) << "-" 
				<< std::setw(2) << std::setfill('0') << (_date.tm_mon + 1) << "-" 
				<< std::setw(2) << std::setfill('0') << _date.tm_mday << " => " 
				<< _value << " = " << finalValue << "\n";
}

void	BitcoinExchange::printClosestDateData()
{
	std::map<std::tm, double, bool(*)(const std::tm&, const std::tm&)>::iterator it = _db.begin();
	while (it->first < _date)
		it++;
	it--;
	double finalValue = _value * it->second;
	std::cout	<< (_date.tm_year + 1900) << "-" 
				<< std::setw(2) << std::setfill('0') << (_date.tm_mon + 1) << "-" 
				<< std::setw(2) << std::setfill('0') << _date.tm_mday << " => " 
				<< _value << " = " << finalValue << "\n";

}

/* 
NOTES:
ss.fail() - did extraction fail
ss.get() != EOF - are there still extra characters in string line
_date = {0}; - only available in later C++

initially we were getting segmentation fault when trying to find and adding a second key/value pair to map
this was because we didn't define the operator< properly and map was unable to order the keys
map uses operator< to order keys (maps is an ordered container)
std::tm does not have a builtin operator< 

if (_date < _db.begin()->first || _date > std::prev(_db.rbegin()->first))
getting an error bc we only defined < and not > 

*/

/* DRAFTS:
	_date.tm_sec = 0;
	_date.tm_min = 0;
	_date.tm_hour = 0;
	_date.tm_mday = 0;
	_date.tm_mon = 0;
	_date.tm_year = 0;
	_date.tm_wday = 0;
	_date.tm_yday = 0;
	_date.tm_isdst = 0;

		// std::memset(&_date, 0, sizeof(_date));
		
*/
