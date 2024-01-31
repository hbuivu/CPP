#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <ctime>
# include <sstream>
# include <fstream>
# include <climits>
# include <cstring>
# include <iomanip>
# include <cctype>
# include <sys/stat.h>

//don't forget to const cast std::tm and don't try to define this in header file!
//including a function definition in a .h file means that it will appear in every translation unit, violating the one definition rule
bool operator < (const std::tm& t1, const std::tm& t2);

//third parameter in std::map<> is the type of function. we will initialize with actual function in cpp file
class BitcoinExchange
{
private:
	static std::map<std::tm, double, bool(*)(const std::tm&, const std::tm&)> _db;
	static std::tm _date;
	static double _value;
	static std::string _line;
	static std::ifstream _dataFile;
	static std::ifstream _inputFile;
	
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();
	BitcoinExchange&	operator=(const BitcoinExchange& src);

	static void checkString(std::string option);
	static void checkDate(std::string option);
	static void	printData();
	static void printClosestDateData();
public:
	static void	openFiles(std::string Input);
	static void	closeFiles();
	static void	parseDatabase();
	static void	parseInput();

	static std::string getLine();

	class InvalidFileException : public std::exception{
	public:
		const char *what() const throw(){return "Error: Could not open file";}
	};
	class BadInputException : public std::exception{
	public:
		const char *what() const throw(){return "Error: Bad input => ";}
	};
	class NegativeNumberException : public std::exception{
	public:
		const char *what() const throw(){return "Error: not a positive number";}
	};
	class LargeNumberException : public std::exception{
	public:
		const char *what() const throw(){return "Error: number too large";}
	};
	class DateRangeException : public std::exception{
	public:
		const char *what() const throw(){return "Error: date out of range";}
	};
	class NoDataException : public std::exception{
	public:
		const char *what() const throw(){return "No data available";}
	};
	class DuplicateException : public std::exception{
	public:
		const char *what() const throw(){return "Error: duplicate date found";}
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

// struct TmComparator {
//     bool operator()(std::tm& lhs, std::tm& rhs) const {
//         return std::mktime(&lhs) < std::mktime(&rhs);
//     }
// };

below can cause issue bc msg is local variable, and what returns pointer to cstring inside msg
however msg might be deallocated once the program exits. 
class BadInputException : public std::exception{
	public:
		const char *what() const throw(){
			std::string msg = "Error: Bad input => " + BitcoinExchange::getLine();
			return msg.c_str();
		}
	};

DRAFTS
# define GREY	"\x1B[30m"
# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE	"\x1B[34m"
# define PURPLE	"\x1B[35m"
# define CYAN	"\x1B[36m"
# define RESET	"\x1B[0m"

*/