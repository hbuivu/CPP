#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <array of positive ints>\n";
		return (1);
	}
	PmergeMe::populateContainers(argv);
	PmergeMe::printList("Before");
	PmergeMe::sortDeque();
	// PmergeMe::sortVector();
	PmergeMe::printList("After");
}