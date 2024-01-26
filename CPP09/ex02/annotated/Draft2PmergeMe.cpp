#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_vect;
std::list<int> PmergeMe::_list;
std::deque<int> PmergeMe::deck
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
}

void	PmergeMe::sortDeque()
{
	if (_deck.size() == 1)
		return ;

	int straggler = -1;
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> mainChain;
	std::deque<int> pend;
	
	if (_deck.size() % 2 == 1)
	{
		straggler = _deck.back();
		_deck.pop_back();
	}
	for (size_t i = 0; i < _deck.size(); i+= 2)
	{
		std::pair<int, int> p = std::make_pair(_deck[i], _deck[i + 1]);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}
	mergeSort<std::deque<std::pair<int, int> > >(pairs);
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	
	std::deque<int> jacob = genJacobIndex<std::deque<int> >(pend.size());
	
	mainChain.push_front(pend.front());
	for (std::deque<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	{
		if (static_cast<size_t>(*it - 1) < pend.size())
		{
			std::deque<int>::iterator insertPos = ftLowerBound(mainChain.begin(), mainChain.end(), pend[*it - 1]);
			mainChain.insert(insertPos, pend[*it - 1]);
		}
	}	
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
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> mainChain;
	std::vector<int> pend;

	if (_vect.size() % 2 == 1)
	{
		straggler = _vect.back();
		_vect.pop_back();
	}
	for (size_t i = 0; i < _vect.size(); i+= 2)
	{
		std::pair<int, int> p = std::make_pair(_vect[i], _vect[i + 1]);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}
	mergeSort<std::vector<std::pair<int, int> > >(pairs);
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
	std::list<std::pair<int, int> > pairs;
	std::list<int> mainChain;
	std::list<int> pend;
	
	if (_list.size() % 2 == 1)
	{
		straggler = _list.back();
		_list.pop_back();
	}
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::pair<int, int> p = std::make_pair(*it, *(++it));
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}
	mergeSort<std::list<std::pair<int, int> > >(pairs);
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