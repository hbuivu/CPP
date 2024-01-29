#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: ./BitcoinExchange <input filename>.txt";
		return (1);
	}
	try
	{
		BitcoinExchange::openFiles(argv[1]);
		BitcoinExchange::parseDatabase();
		BitcoinExchange::parseInput();
	}
	catch(BitcoinExchange::BadInputException &e) //special catch for bad input since we have to print out line
	{
		std::cerr << e.what() << BitcoinExchange::getLine() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	BitcoinExchange::closeFiles();
	return (0);
}