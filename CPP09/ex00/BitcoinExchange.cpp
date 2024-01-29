#include "BitcoinExchange.hpp"

//initialize with overloaded operator<
std::map<std::tm, double, bool(*)(const std::tm&, const std::tm&)> BitcoinExchange::_db(&operator<);
std::tm BitcoinExchange::_date;
double BitcoinExchange::_value = 0;
std::string	BitcoinExchange::_line = "";
std::ifstream BitcoinExchange::_dataFile;
std::ifstream BitcoinExchange::_inputFile;

bool operator < (const std::tm& t1, const std::tm& t2)
{
	return (std::mktime(const_cast<std::tm*>(&t1)) < std::mktime(const_cast<std::tm*>(&t2)));
};

void	BitcoinExchange::checkString(std::string option)
{
	if (option == "database" && _line != "date,exchange_rate")
		throw InvalidFileException();
	else if (option == "input" && _line != "date | value")
		throw InvalidFileException();
	else if (option == "")
	{
		//check for + since a single + in front of a number is usually interpreted as a positive number
		if (_line.find("+") != std::string::npos) 
			throw BadInputException();
		// make sure string is long enough to check the proper indices
		//check that there are no numbers like this 0000000000002
		if (_line.length() >= 11 && (_line[7] != '-' || isdigit(_line[10])))
			throw BadInputException();
	}
}

void	BitcoinExchange::checkDate(std::string option)
{
	//check that year falls in between 2009 (when bitcoin started) and 2024 (current year). don't forget to subtract 1900
	if (_date.tm_year < 109 || _date.tm_year > 124)
		throw DateRangeException();

	//if month or day exceeds max or goes below 0, it will be calculated in as overflow into the next year
	if (_date.tm_mon < 0 || _date.tm_mon > 11 ||
		_date.tm_mday < 0 || _date.tm_mday > 31)
		throw BadInputException();
	
	//check for April/June/Sept/Nov - only 30 days. don't forget months start from 0 - 11
	if ((_date.tm_mon == 3 || _date.tm_mon == 5 || _date.tm_mon == 8 || _date.tm_mon == 10) && _date.tm_mday > 30)
		throw BadInputException();
	
	//account for leap years - as it turns out, using tm struct was not particularly useful...
	//leap year - year number must be divisible by 4. if it is end of the century year (ex: 1900) it must be divisible by 400
	if ((_date.tm_year % 4 != 0 && _date.tm_mon == 1 && _date.tm_mday > 28) || 
		(_date.tm_year % 100 == 0 && _date.tm_year % 400 != 0 && _date.tm_mon == 1 && _date.tm_mday > 28))
		throw BadInputException();

	//check if the date is valid;
	if (std::mktime(&_date) == -1)
		throw BadInputException();

	// for database, check if date is duplicated in file
	if (option == "database" && _db.find(_date) != _db.end())
		throw DuplicateException();
	
	//for input, check if date is falls outside of range in data.csv
	//we switch the statement in the second half because we only defined operator <
	if (option == "input" && (_date < _db.begin()->first || _db.rbegin()->first < _date))		
		throw DateRangeException();
}

void	BitcoinExchange::openFiles(std::string Input)
{
	_dataFile.open("data.csv"); 
	if (!_dataFile.is_open())
		throw InvalidFileException();
	_inputFile.open(Input.c_str());
	if (!_inputFile.is_open())
		throw InvalidFileException();
}

void	BitcoinExchange::closeFiles()
{
	if (_dataFile.is_open())
		_dataFile.close();
	if (_inputFile.is_open())
		_inputFile.close();
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

//see parseInput for notes
void	BitcoinExchange::parseDatabase()
{
	std::getline(_dataFile, _line);
	checkString("database");
	while (std::getline(_dataFile, _line))
	{
		checkString("");
		std::istringstream ss(_line);
		char dash1, dash2, comma;
		double exchangeRate;
		ss	>> _date.tm_year >> dash1 >> _date.tm_mon >> dash2
			>> _date.tm_mday >> comma >> exchangeRate;
		if (ss.fail() || ss.get() != EOF || 
			dash1 != '-' ||dash2 != '-' || comma != ',' ||
			exchangeRate < 0 || exchangeRate > INT_MAX)
			throw BadInputException();
		_date.tm_year -= 1900;
		_date.tm_mon -= 1;
		checkDate("database");
		_db[_date] = exchangeRate;	
	}
}

void	BitcoinExchange::parseInput()
{
	//check if database is empty
	if (_db.empty())
		throw NoDataException();
	std::getline(_inputFile, _line);
	checkString("input");
	while (std::getline(_inputFile, _line))
	{
		try
		{
			//check string for invalid inputs
			checkString("");

			//convert std::string _line to a stringstream
			std::istringstream ss(_line);
			char dash1, dash2, pipe; //istringstream ignores leading white spaces
			ss	>> _date.tm_year >> dash1 >> _date.tm_mon >> dash2
				>> _date.tm_mday >> pipe >> _value;

			//ss.fail() - if extraction fails; ss.get() - if there is still more in the string
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
			
			//check date to make sure it's valid
			checkDate("input");
			
			if(_db.find(_date) != _db.end())
				printData();
			else
				printClosestDateData();
		}
		catch(BadInputException &e) //special catch for bad input since we have to print out line
		{
			std::cerr << e.what() << _line << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}

std::string	BitcoinExchange::getLine()
{
	return _line;
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

static members cannot be const bc const is related to this and this does not exist in const

*/

/* DRAFTS:
std::memset(&_date, 0, sizeof(_date));
*/
