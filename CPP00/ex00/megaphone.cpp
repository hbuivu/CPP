#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
		for (int j = 0; j < argv[i][j]; j++)
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
	std::cout << '\n';
	return (0);	
}

// int main(int argc, char **argv)
// {
// 	if (argc == 1)
// 	{
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
// 		return (0);
// 	}
// 	for (int i = 1; i < argc; i++)
// 	{
// 		std::string str{argv[i]};
// 		for (int j = 0; j < str.length(); j++)
// 			std::cout << static_cast<char>(std::toupper(str[j]));
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }