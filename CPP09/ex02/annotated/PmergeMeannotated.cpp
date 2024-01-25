#include "PmergeMe.hpp"

std::deque<int>		PmergeMe::_deck;
std::vector<int>	PmergeMe::_vect;
std::list<int>		PmergeMe::_list;

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
		_list.push_back(num);
	}
}

void	PmergeMe::printList(std::string const & str)
{
	if (str == "Before")
		std::cout << "Before: ";
	else if (str == "After")
		std::cout << "After: ";
	for (std::deque<int>::iterator it = _deck.begin(); it != _deck.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "List:   ";
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

void	PmergeMe::sortDeque()
{
	//check if size of list is 1
	if (_deck.size() == 1)
		return ;

	//check for straggler - if array is odd number
	int straggler = -1;
	if (_deck.size() % 2 == 1)
	{
		straggler = _deck.back();
		_deck.pop_back(); //we need this, because we don't want to create a pair with this number
	}

	//create pair, order pair, insert pair into new deque pairs
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < _deck.size(); i+= 2) //deck has indices!
	{
		std::pair<int, int> p = std::make_pair(_deck[i], _deck[i + 1]);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}
	
	//sort pairs. if no comparator is specified, sort uses first element to sort
	// std::sort(pairs.begin(), pairs.end()); we can't use this bc we have to write our own
	mergeSort<std::deque<std::pair<int, int> > >(pairs);

	//create main chain and pend
	std::deque<int> mainChain;
	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	//create Jacobsthal Sequence
	std::deque<int> jacob = genJacobIndex<std::deque<int> >(pend.size());

	//push first number in
	mainChain.push_front(pend.front());

	//insert pend elements using index from jacob list and binary search
	for (std::deque<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	{
		if (static_cast<size_t>(*it - 1) < pend.size())
		{
			std::deque<int>::iterator insertPos = ftLowerBound(mainChain.begin(), mainChain.end(), pend[*it - 1]);
			mainChain.insert(insertPos, pend[*it - 1]);
		}
	}	
	
	//insert straggler
	if (straggler != -1)
	{
		std::deque<int>::iterator insertPos = ftLowerBound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}
	_deck = mainChain;
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
	if (_vect.size() == 1)
		return ;

	int straggler = -1;
	if (_vect.size() % 2 == 1)
	{
		straggler = _vect.back();
		_vect.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < _vect.size(); i+= 2)
	{
		std::pair<int, int> p = std::make_pair(_vect[i], _vect[i + 1]);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}
	
	mergeSort<std::vector<std::pair<int, int> > >(pairs);

	std::vector<int> mainChain;
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	
	std::vector<int> jacob = genJacobIndex<std::vector<int> >(pend.size());

	mainChain.insert(mainChain.begin(), pend.front());

	for (std::vector<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	{
		if (static_cast<size_t>(*it - 1) < pend.size())
		{
			std::vector<int>::iterator insertPos = ftLowerBound(mainChain.begin(), mainChain.end(), pend[*it - 1]);
			mainChain.insert(insertPos, pend[*it - 1]);
		}
	}	

	if (straggler != -1)
	{
		std::vector<int>::iterator insertPos = ftLowerBound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}
	_vect = mainChain;
}

void	PmergeMe::sortList()
{
	if (_list.size() == 1)
		return ;

	int straggler = -1;
	if (_list.size() % 2 == 1)
	{
		straggler = _list.back();
		_list.pop_back();
	}
	
	std::list<std::pair<int, int> > pairs;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::pair<int, int> p = std::make_pair(*it, *(++it));
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}
	
	mergeSort<std::list<std::pair<int, int> > >(pairs);

	std::list<int> mainChain;
	std::list<int> pend;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		mainChain.push_back(it->first);
		pend.push_back(it->second);
	}
	
	std::list<int> jacob = genJacobIndex<std::list<int> >(pend.size());

	mainChain.insert(mainChain.begin(), pend.front());
	
	for (std::list<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	{
		if (static_cast<size_t>(*it - 1) < pend.size())
		{
			std::list<int>::iterator pendIT = pend.begin();
			std::advance(pendIT, (*it - 1));
			std::list<int>::iterator insertPos = ftLowerBound(mainChain.begin(), mainChain.end(), *pendIT);
			mainChain.insert(insertPos, *pendIT);
		}
	}	

	if (straggler != -1)
	{
		std::list<int>::iterator insertPos = ftLowerBound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}
	_list = mainChain;
}


/* NOTES:
std::pair is a type
std::make_pair is a utility function that helps to make std::pair with type deduction
ftLowerBound uses binary search and we could have used that to insert numbers into mainchain
however the subject asked us to write our own algorithms sadly
*/