#include <string>
#include <iostream>

int main(void)
{
	std::string str = "123.abcdakf";

	int i = std::stoi(str);
	float f = std::stof(str);
	double d = std::stod(str);

	std::cout << "int: " << i << " float: " << f << " double: " << d << std::endl;
}