#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

//check if pragma once works in valgrind

# include <iostream>
# include <string>
# include <map>
# include <ctime>
# include <sstream>
# include <fstream>
# include <climits>

# define GREY	"\x1B[30m"
# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE	"\x1B[34m"
# define PURPLE	"\x1B[35m"
# define CYAN	"\x1B[36m"
# define RESET	"\x1B[0m"

// struct TmComparator {
//     bool operator()(std::tm& lhs, std::tm& rhs) const {
//         return std::mktime(&lhs) < std::mktime(&rhs);
//     }
// };

bool operator < (std::tm& t1, std::tm& t2)
{
	return (std::mktime(&t1) < std::mktime(&t2));
};

class BitcoinExchange
{
private:
	static std::map<std::tm, double, >	_db;
	// static std::map<std::tm, double>	_db;
	// static std::tm		_date;
	static double		_value;
	static std::string	_input;
	static std::string	_line;
	
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();
	BitcoinExchange&	operator=(const BitcoinExchange& src);
public:
	static void			parseDatabase();
	static std::string&	getLine();
	// static void	parseInput(std::string Input);

	class InvalidFileException : public std::exception{
	public:
		const char *what() const throw(){return "Error: Could not open file";}
	};
	class BadInputException : public std::exception{
	public:
		const char *what() const throw(){
			std::string msg = "Error: Bad input => " + BitcoinExchange::getLine();
			return msg.c_str();
		}
	};
	class NegativeNumberException : public std::exception{
	public:
		const char *what() const throw(){return "Error: not a positive number";}
	};
	class LargeNumberException : public std::exception{
	public:
		const char *what() const throw(){return "Error: number too large";}
	};
	class DuplicateException : public std::exception{
	public:
		const char *what() const throw(){return "Error: duplicate date found";}
	};
	class DateRangeException : public std::exception{
	public:
		const char *what() const throw(){return "Error: date out of range";}
	};
};

#endif

/* NOTES:
#pragma once is nice but technically only part of C++11
map<key, value, CompareType, AllocatorType>
-last 2 are not mandatory
1. CompareType - specify custom comparison function for keys
	uses std::less<KeyType> - uses '<' operator
	if key does not have a default '<' operator, we have to define one
2. AllocatorType - specify custom allocator for memory management
	default std::allocator


*/