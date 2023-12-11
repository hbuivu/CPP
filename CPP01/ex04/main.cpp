#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./SedIsForLosers <filename> <stringToReplace> <stringReplacement>" << std::endl;
		return (1);
	}
	Sed sed(argv[1], argv[2], argv[3]);
	sed.replace();

}