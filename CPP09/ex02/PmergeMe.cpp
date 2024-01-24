#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	(void)src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& src)
{
	(void)src;
	return *this;
}

void	PmergeMe::populateContainers(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::istringstream ss(argv[i]);
		int num;
		ss >> num;
		if (ss.fail() || ss.get() != EOF || num < 0)
			throw InvalidInputException();
		_deck.push_back(num);
		_vect.push_back(num);
	}
}

void	PmergeMe::printList(std::string const & str)
{
	if (str == "Before")
		std::cout << "Before: ";
	else if (str == "After")
		std::cout << "After: ";
	for (std::vector<int>::iterator it; it != _vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::sortDeque()
{
	//check for straggler - if array is odd number
	int straggler = -1;
	if (_deck.size() % 2 == 1)
	{
		straggler = _deck.back();
		_deck.pop_back();
	}

	//create pair, order pair, insert pair into new deque pairs
	std::deque<std::pair<int, int>> pairs;
	for (int i = 0; i < _deck.size(); i+= 2) //deck has indices!
	{
		std::pair<int, int> p = std::make_pair(_deck[i], _deck[i + 1]);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}
	
	//sort pairs. if no comparator is specified, sort uses first element to sort
	//might have to write custom recursive sort function here
	std::sort(pairs.begin(), pairs.end());

	//create main chain and pend
	std::deque<int> mainChain;
	std::deque<int> pend;
	for (int i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	
	//create Jacobsthal Sequence
	std::deque<int> jacob = genJacobIndex<std::deque<int>>(pend.size());

	//push first number in
	mainChain.push_front(pend.front());

	//insert pend elements using index from jacob list and binary search
	for (std::deque<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	{
		if (*it < pend.size())
		{
			std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[*it]);
			mainChain.insert(insertPos, pend[*it]);
		}
	}	
	
	//insert straggler
	if (straggler != -1)
	{
		std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}

}

int PmergeMe::Jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void	PmergeMe::sortVector()
{

}
/* NOTES:
std::pair is a type
std::make_pair is a utility function that helps to make std::pair with type deduction*/