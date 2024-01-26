#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_vect;
std::vector<int> PmergeMe::_bvect;
std::list<int> PmergeMe::_list;

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

int PmergeMe::Jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void	PmergeMe::vMerge(std::vector<std::pair<int, int> > & left, std::vector<std::pair<int, int> > & right, std::vector<std::pair<int, int> > & array)
{
	size_t lsize = left.size();
	size_t rsize = right.size();
	size_t l = 0;
	size_t r = 0;
	size_t a = 0;

	while (l < lsize && r < rsize)
	{
		if (left[l].first <= right[r].first)
		{
			array[a] = left[l];
			l++;
		}
		else
		{
			array[a] = right[r];
			r++;
		}
		a++;
	}
	while (l < lsize)
	{
		array[a] = left[l];
		l++;
		a++;
	}
	while (r < rsize)
	{
		array[a] = right[r];
		r++;
		a++;
	}
}

void	PmergeMe::vMergeSort(std::vector<std::pair<int, int> > & array)
{
	size_t arraySize = array.size();
	if (array.size() < 2)
		return ;
	size_t mid = arraySize / 2;
	std::vector<std::pair<int, int> > left; 
	std::vector<std::pair<int, int> > right;
	size_t i = 0;
	for (; i < mid; i++)
		left.push_back(array[i]);
	for (; i < arraySize; i++)
		right.push_back(array[i]);
	vMergeSort(left);
	vMergeSort(right);
	vMerge(left, right, array);
}

void	PmergeMe::lMerge(std::list<std::pair<int, int> > & left, std::list<std::pair<int, int> > & right, std::list<std::pair<int, int> > & array)
{
	std::list<std::pair<int, int> >::iterator leftIT = left.begin();
	std::list<std::pair<int, int> >::iterator rightIT = right.begin();
	std::list<std::pair<int, int> >::iterator arrayIT = array.begin();
	
	while (leftIT != left.end() && rightIT != right.end())
	{
		if (*leftIT <= *rightIT)
		{
			*arrayIT = *leftIT;
			leftIT++;
		}
		else
		{
			*arrayIT = *rightIT;
			rightIT++;
		}
		arrayIT++;
	}
	while (leftIT != left.end())
	{
		*arrayIT = *leftIT;
		leftIT++;
		arrayIT++;
	}
	while (rightIT != right.end())
	{
		*arrayIT = *rightIT;
		rightIT++;
		arrayIT++;
	}	
}

void	PmergeMe::lMergeSort(std::list<std::pair<int, int> > & array)
{
	size_t arraySize = array.size();
	if (array.size() < 2)
		return ;
	size_t mid = arraySize / 2;
	std::list<std::pair<int, int> >::iterator arrayIT = array.begin();
	std::list<std::pair<int, int> > left;
	std::list<std::pair<int, int> > right;
	size_t i = 0;
	for (; i < mid; i++)
	{
		left.push_back(*arrayIT);
		arrayIT++;
	}
	for (; i < arraySize; i++)
	{
		right.push_back(*arrayIT);
		arrayIT++;
	}
	// std::cout << "left: ";
	// for (std::list<std::pair<int, int> >::iterator it = left.begin(); it != left.end(); it++)
	// 	std::cout << "(" << it->first << "," << it->second << ") ";
	// std::cout << "\n";
	// std::cout << "right: ";
	// for (std::list<std::pair<int, int> >::iterator it = right.begin(); it != right.end(); it++)
	// 	std::cout << "(" << it->first << "," << it->second << ") ";
	// std::cout << "\n";
	lMergeSort(left);
	lMergeSort(right);
	lMerge(left, right, array);
}

void	PmergeMe::populateVect(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::istringstream ss(argv[i]);
		int num;
		ss >> num;
		if (ss.fail() || ss.get() != EOF || num < 0)
			throw InvalidInputException();
		_vect.push_back(num);
	}
}

void	PmergeMe::populateList(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::istringstream ss(argv[i]);
		int num;
		ss >> num;
		if (ss.fail() || ss.get() != EOF || num < 0)
			throw InvalidInputException();
		_list.push_back(num);
	}
}
void	PmergeMe::printList(std::string const & str)
{
	if (str == "Before")
	{
		std::cout << "Before: ";
		for (std::vector<int>::iterator it = _bvect.begin(); it != _bvect.end(); it++)
			std::cout << *it << " ";
	}
	else if (str == "After")
	{
		std::cout << "After:\n";
		std::cout << "Vector: ";
		for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); it++)
			std::cout << *it << " ";
		std::cout << "\n";
		std::cout << "List:   ";
		for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
			std::cout << *it << " ";
	}
	std::cout << "\n";
}

void	PmergeMe::sortVector(char **argv)
{
	try
	{
		populateVect(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	_bvect = _vect;
	
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
	vMergeSort(pairs);
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	std::vector<int> jacob = genJacobIndex<std::vector<int> >(pend.size());
	// std::cout << "jacob: \n";
	// for (std::vector<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << "\n";
	
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

void	PmergeMe::sortList(char **argv)
{
	try
	{
		populateList(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
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
		int firstVal = *it;
		int secondVal = *(++it);
		std::pair<int, int> p = std::make_pair(firstVal, secondVal);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}

	lMergeSort(pairs);

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

size_t	PmergeMe::getSize()
{
	return _vect.size();
}

/* NOTES:
std::pair is a type
std::make_pair is a utility function that helps to make std::pair with type deduction
ftLowerBound uses binary search and we could have used that to insert numbers into mainchain
however the subject asked us to write our own algorithms sadly

std::pair<int, int> p = std::make_pair(*it, *(++it)); //this will give undefined behavior. we are modifying it before it can be evaluated

*/