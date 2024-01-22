#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <string>
# include <map>
# include <ctime>
# include <sstream>
# include <fstream>
# include <climits>

bool operator < (const std::tm& t1, const std::tm& t2)
{
	return (std::mktime(const_cast<std::tm*>(&t1)) < std::mktime(const_cast<std::tm*>(&t2)));
};

class Test
{
private:
	static std::map<std::tm, double, bool(*)(const std::tm&, const std::tm&)> _db;
public:
	static void fun();
};

#endif