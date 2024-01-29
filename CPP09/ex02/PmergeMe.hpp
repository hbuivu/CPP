#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <list>
# include <sstream>
# include <fstream>
# include <iostream>
# include <algorithm>
# include <utility>
# include <iterator>

class PmergeMe
{
private:
	static std::vector<int>	_vect;
	static std::vector<int>	_bvect;
	static std::list<int>	_list;

	PmergeMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();
	PmergeMe &	operator=(PmergeMe const & src);

	static int	Jacobsthal(int s);
	static void	vMerge(std::vector<std::pair<int, int> > & left, std::vector<std::pair<int, int> > & right, std::vector<std::pair<int, int> > & array);
	static void	vMergeSort(std::vector<std::pair<int, int> > & array);
	static void	lMerge(std::list<std::pair<int, int> > & left, std::list<std::pair<int, int> > & right, std::list<std::pair<int, int> > & array);
	static void	lMergeSort(std::list<std::pair<int, int> > & array);

	template<typename T>
	static T	genJacobIndex(size_t size)
	{
		T container;
		int prevJacobNum = 1;
		int jacobNum = 3;
		int i = 3;
		
		if (size == 2 || size == 3) //manually do this since we start jacobNUm at 3
		{
			container.push_back(3);
			container.push_back(2);
		}

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
	};

	template<typename Iterator>
	static Iterator ftLowerBound(Iterator beginIT, Iterator endIT, int numToFind)
	{
		if (beginIT == endIT)
			return (beginIT);
		int arraySize = std::distance(beginIT, endIT) + 1; 
		int mid = arraySize / 2;
		if (arraySize == 2)
		{
			if (*beginIT >= numToFind)
				return beginIT;
			else
				return endIT;
		}
		Iterator oldBeginIT = beginIT;
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
public:
	static void		populateVect(char **argv);
	static void		populateList(char **argv);
	static void		sortVector();
	static void		sortList();
	static void 	printList(std::string const & str);
	static size_t	getSize();

	class InvalidInputException : public std::exception{
		const char *what() const throw(){return "Invalid input detected";};
	};
};

#endif

/* NOTES:
-create two different containers - list and probably vector/deque
-populate containers with numbers from cmd line
-print out Before list

1. determine if array is even or odd. if odd, set last number as straggler. it will be last to be inserted
2. divide sequence to sort into pairs
3. sort each pair [greater, less]
4. sort sequence recursively by value of greater number in pair
5. Main Chain - creaete array of ordered greater number from each pair - insert into main chain
4. place less num of each pair into temporary pend array
5. insert the first number in front
6. build jacobsthal numbers based on number of insertions
7. use binary search to insert each pend  element into main chain
8. insert straggler if there

Don't forget to time the sorting in each container and print it out

const can't be applied to static functions
When you apply the const qualifier to a nonstatic member function, 
it affects the this pointer. For a const-qualified member function of class C, 
the this pointer is of type C const*, whereas for a member function that is 
not const-qualified, the this pointer is of type C*.

A static member function does not have a this pointer (such a function is 
not called on a particular instance of a class), so const qualification of a 
static member function doesn't make any sense.

template<typename T,
			typename = std::enable_if_t<std::is_same_v<Container, std::deque<int>> ||
						 std::is_same_v<Container, std::vector<int>>>>
I wanted to restrict template function to vector and deque only. 
It only works in C++11 :(

std::lower_bound  and std::upper_bound uses binary search to find the position of an element
std::lower_bound returns an iterator pointing to the first element NOT LESS THAN the given value
if element is not present, it returns an iterator pointing to first element greater than given value
returns end if value is greater than all elements in the array

std::upper_bound returns an iterator pointing to the first element GREATER THAN the given value

the difference between upper and lower bound
value a a a b b b c c c
index 0 1 2 3 4 5 6 7 8
bound       l     u

if we are lookng for b, l will give you first instance of b whereas u will give the first element greater than b
otherwise if b is not there, both l and u will give first instance of c
*/