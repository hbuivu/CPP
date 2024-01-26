#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template<typename T>
T	PmergeMe::genJacobIndex(size_t size)
{
	T container;
	int prevJacobNum = 1;
	int jacobNum = 3;
	int i = 3;

	while (size > static_cast<size_t>(jacobNum))
	{
		jacobNum = Jacobsthal(i);
		container.push_back(jacobNum);
		for (int index = jacobNum - 1; index > prevJacobNum; index--)
			container.push_back(index);
		i++;
		prevJacobNum = jacobNum;
	}
	return (container);
}

template<typename T>
void	PmergeMe::merge(T & left, T & right, T & array)
{
	typename T::iterator leftIT	= left.begin();
	typename T::iterator rightIT = right.begin();
	typename T::iterator arrayIT = array.begin();
	
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

template<typename T>
static void	mergeSort(T & array)
{
	size_t arraySize = array.size();

	if (array.size() < 2)
		return ;
	
	size_t mid = arraySize / 2;
	size_t i = 0;
	T left, right;
	typename T::iterator arrayIT = array.begin();

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
	mergeSort(left);
	mergeSort(right);
	merge(left, right, array);
};

template<typename Iterator>
Iterator PmergeMe::ftLowerBound(Iterator beginIT, Iterator endIT, int numToFind)
{
	if (beginIT == endIT)
		return (beginIT);

	int arraySize = std::distance(beginIT, endIT) + 1; 
	int mid = arraySize / 2;
	Iterator oldBeginIT = beginIT;

	if (arraySize == 2)
	{
		if (*beginIT >= numToFind)
			return beginIT;
		else
			return endIT;
	}
	if (arraySize % 2 == 1)
		std::advance(beginIT, mid);
	else
		std::advance(beginIT, mid - 1);
	if (numToFind == *beginIT)
		return beginIT;
	if (numToFind < *beginIT)
		return ftLowerBound(oldBeginIT, beginIT, numToFind);
	else
	{
		beginIT++;
		return ftLowerBound(beginIT, endIT, numToFind);
	}
};

#endif