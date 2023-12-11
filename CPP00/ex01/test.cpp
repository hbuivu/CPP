#include <iostream>
#include <string>

int main(void)
{
	std::string str = "";

	std::cout << "enter a string: " << std::flush;
	std::getline(std::cin, str);	
	while (str.empty())
	{
		std::cout << "field empty, please enter a string." << std::endl;
		std::getline(std::cin, str);
	}
	std:: cout << "you entered: " << str << std::endl;
}