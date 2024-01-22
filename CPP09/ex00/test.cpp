// #include <iostream>
// #include <string>
// #include <map>
// #include <ctime>
// #include <sstream>
// #include <fstream>

// int main()
// {
// 	std::string line = "2011 | 02 | 02";
// 	std::istringstream ss(line);

// 	std::tm date = {0};
// 	std::string c1, c2;
// 	ss >> date.tm_year >> c1 >> date.tm_mon >> c2 >> date.tm_mday;
// 	if (ss.fail())
// 		std::cout << "failed\n";
// 	std::cout << date.tm_year << c1 << date.tm_mon << c2 << date.tm_mday << "\n"; 
// }


#include "test.hpp"

std::map<std::tm, double, bool(*)(const std::tm&, const std::tm&)> Test::_db(&operator<);

void Test::fun()
{
	std::tm date;
	date.tm_year = 2009 - 1900;
	date.tm_mon = 10 - 1;
	date.tm_mday = 1;

	_db[date] = 1;

	date.tm_year = 2010 - 1900;
	date.tm_mon = 11 - 1;
	date.tm_mday = 2;

	_db[date] = 1;
}

int main()
{
	Test::fun();
}