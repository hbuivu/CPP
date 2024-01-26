#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <array of positive ints>\n";
		return (1);
	}

	clock_t	vStart = clock();
	PmergeMe::sortVector(argv);
	clock_t	vEnd = clock();

	clock_t	lStart = clock();
	PmergeMe::sortList(argv);
	clock_t	lEnd = clock();

	PmergeMe::printList("Before");
	PmergeMe::printList("After");

	double vTime = static_cast<double>(vEnd - vStart);
	double lTime = static_cast<double>(lEnd - lStart);
	std::cout << "time to process a range of " << PmergeMe::getSize() << " elements with std::vector: " << vTime << "us\n";
	std::cout << "time to process a range of " << PmergeMe::getSize() << " elements with std::list: " << lTime << "us\n";
}

/* NOTES:
clock returns the amount of time (clock ticks) spent in program
CLOCKS_PER_SEC - there are 1,000,000 clock ticks per second
us - microsecond = 1/millionth of a second
 */