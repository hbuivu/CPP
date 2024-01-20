#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

//check if pragma once works in valgrind

#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <sstream>
#include <fstream>

#define GREY	"\x1B[30m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define PURPLE	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define RESET	"\x1B[0m"

class BitcoinExchange
{
private:
	std::map<std::tm, double>	_db;
	std::string					_curLine;
public:
	class	GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){
			return "Grade too low. The lowest possible grade is 150";
		}
	};
}

#endif

//#pragma once is nice but technically only part of C++11