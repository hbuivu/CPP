#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <array of positive ints>\n";
		return (1);
	}
	try
	{
		PmergeMe::populateContainers(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	PmergeMe::printList("Before");
	// clock_t	dStart = clock();
	PmergeMe::sortDeque();
	// clock_t	dEnd = clock();

	// clock_t	vStart = clock();
	// PmergeMe::sortVector();
	// clock_t	vEnd = clock();

	// clock_t	lStart = clock();
	// PmergeMe::sortList();
	// clock_t	lEnd = clock();

	// double dTime = static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC * 1e6;
	// double vTime = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC * 1e6;
	// double lTime = static_cast<double>(lEnd - lStart) / CLOCKS_PER_SEC * 1e6;
	// std::cout << "dTime is: " << dTime << "\n";
	// std::cout << "vTime is: " << vTime << "\n";
	// std::cout << "lTime is: " << lTime << "\n";

	PmergeMe::printList("After");
}