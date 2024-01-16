#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

bool	isMisplacedF(std::string::const_iterator it, const std::string& literal)
{
	// if (*it == 'f')
	// 	std::cout << (++it == literal.end()) << "\n";
	return *it == 'f' && ++it != literal.end();
}

int main(void)
{
	// std::string str = "123.abcdakf";

	// int i = std::stoi(str);
	// float f = std::stof(str);
	// double d = std::stod(str);

	// std::cout << "int: " << i << " float: " << f << " double: " << d << std::endl;

	// std::string str = "4.5f";
	// std::string::const_iterator it = str.begin();
	// for (; it != str.end(); it++)
	// 	std::cout << isMisplacedF(it, str);

	// try
	// {
	// 	std::stoi("2147483648");
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << "Hello\n";
	// }

	// std::string str = "214748364999";

	// float f = stof(str);
	// std::cout << f << "\n";
	// std::cout << std::fixed << std::setprecision(1) << f << "\n";

	// long double stdnum = strtold(str.c_str(), NULL);
	// // int i  = std::atoi(str.c_str());
	// std::cout << std::fixed << std::setprecision(1) << stdnum << "\n";
	// std::cout << std::fixed << std::setprecision(1) << 2147483647.0f << "\n";
	// std::cout  << static_cast<long double>(100000.14) << "\n";
	// std::string str1 = "100000.14";
	std::string str1 = "1000adsfjkadj";
	// long double num = strtold(str1.c_str(), NULL);
	double num = atof(str1.c_str());
	// long double num = stold(str1);
	// std::cout << num << "\n";

	std::cout << num << "\n";
    // std::cout << std::fixed << std::setprecision(2) << num << "\n";
	// std::cout << strtold(str1.c_str(), NULL) << "\n";

}

