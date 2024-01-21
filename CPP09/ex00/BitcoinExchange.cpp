#include "BitcoinExchange.hpp"
#include <cstring>

std::map<std::tm, double, >	BitcoinExchange::_db;
// std::map<std::tm, double>	BitcoinExchange::_db;
std::tm		BitcoinExchange::_date;
double		BitcoinExchange::_value = 0;
std::string	BitcoinExchange::_input;
std::string	BitcoinExchange::_line;

std::string&	BitcoinExchange::getLine()
{
	return _line;
}

void	BitcoinExchange::parseDatabase()
{
	//open database file and check if it opened properly
	std::ifstream infile("data.csv"); 
	if (!infile.is_open())
		throw InvalidFileException();
	std::getline(infile, _line);
	std::cout << "line is: " << _line << "\n";
	//check that headers are correct
	if (_line != "date,exchange_rate")
		throw InvalidFileException();
	while (std::getline(infile, _line))
	{
		try
		{
			// std::memset(&_date, 0, sizeof(_date));
			std::cout << "line is: " << _line << "\n";
			// _date = {0}; //not available in c++98
			_date.tm_sec = 0;
			_date.tm_min = 0;
			_date.tm_hour = 0;
			_date.tm_mday = 0;
			_date.tm_mon = 0;
			_date.tm_year = 0;
			_date.tm_wday = 0;
			_date.tm_yday = 0;
			_date.tm_isdst = 0;
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
			std::cout << "Here\n";
			// if (_db.find(_date) != _db.end()) //if a copy is found already
			// 	throw DuplicateException();
			std::cout << "adding to map\n";
			_db[_date] = exchangeRate;
			std::cout << "added to map successfully\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}

// void	BitcoinExchange::parseInput(std::string Input)
// {
// 	std::ifstream infile(Input);
// 	if (!infile.is_open())
// 		throw InvalidFileException();
// 	std::string _line;
// 	std::getline(infile, _line);
// 	if (_line != "date | value")
// 		throw InvalidFileException();
// 	while (std::getline(infile, _line))
// 	{
// 		_date = {0};
// 		std::istringstream ss(_line);
// 		char dash1, dash2, pipe; //istringstream ignores leading white spaces
// 		ss	>> _date.tm_year >> dash1 >> _date.tm_mon >> dash2
// 			>> _date.tm_mday >> pipe >> _value;
// 		if (ss.fail() || ss.get() != EOF ||
// 			dash1 != '-' ||dash2 != '-' || pipe != '|')
// 			throw BadInputException();
// 		else if (_value < 0)
// 			throw NegativeNumberException();
// 		else if (_value > 1000)
// 			throw LargeNumberException(); 
// 		//adjust year and month to match data requirements in struct
// 		_date.tm_year -= 1900; //year range starts from 1900
// 		_date.tm_mon -= 1 //month range 0-11
// 		if (std::mktime(&_date) == -1)
// 			throw BadInputException();
// 		if (_date < _database.begin() || _date > database.end()) //somethign like this
// 			throw DateRangeException();
// 		if(_database.find(_date) != _database.end())
// 			printData(NULL);
// 		// else
// 		// {
// 		// 	try
// 		// 	{
// 		// 		std::tm *closestDate = checkDate();
// 		// 		printData(closestDate);
// 		// 	}
// 		// 	catch(const std::exception& e)
// 		// 	{
// 		// 		std::cerr << e.what() << '\n';
// 		// 	}
			
// 		// }
// 			//use while loop to iterate over database to check when _date becomes bigger than input _date
// 			//is it possible to match year and month too?
// 	}
// }

// void	BitcoinExchange::printData(std::tm* closestDate)
// {	
// 	int	finalValue
// 	if (closestDate == NULL)
// 		finalValue = _value * _db[_date]; //we do this bc we modify _date to get the correctly printed year and month
// 	else
// 		finalValue = _value * closestDate->second;
// 	_date.tm_year += 1900;
// 	_date.tm_mon += 1;
// 	std::cout	<< _date.tm_year << "-" << _date.tm_mon << "-" << _date.tm_mday 
// 				<< " => " << _value << " = " << finalValue << "\n";
// }

// std::tm*	BitcoinExchange::checkDate()
// {

// }

/* NOTES:
//ss.fail() - did extraction fail
//ss.get() != EOF - are there still extra characters in string line
*/
