#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Usage: ./BitcoinExchange <filename>.txt";
		return (1);
	}
	try
	{
		BitcoinExchange::parseDatabase();
		// BitcoinExchange::parseInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}