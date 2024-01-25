#pragma once

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
	static std::deque<int>	_deck;
	static std::vector<int>	_vect;
	static std::list<int>	_list;

	PmergeMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();
	PmergeMe &	operator=(PmergeMe const & src);

	static int Jacobsthal(int s);
public:
	static void	sortDeque();
	static void	sortVector();
	static void	sortList();
	static void	populateContainers(char **argv);
	static void printList(std::string const & str);

	class InvalidInputException : public std::exception{
		const char *what() const throw(){return "Invalid input detected";};
	};
	
	template<typename T>
	static T	genJacobIndex(size_t size)
	{
		T container;
		int	prevJacobNum = 1;
		int	jacobNum = 3;
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
	};

	/* --------------------------------------------------------------------------- */
	//Indexed version - works with Deque and Vector
	// merging and sorting left and right arrays back into bigger array
	// REMEMBER TO PASS BY REF, NOT BY COPY. otherwise the sorting won't translate 
	template<typename T>
	static void	merge(T & left, T & right, T & array)
	{
		//find sizes of left and right array
		size_t lsize = left.size();
		size_t rsize = right.size();

		//set index counters for left, right, and array
		size_t l = 0;
		size_t r = 0;
		size_t a = 0;

		//sort numbers from left and right into array, comparing the lowest indexed elements from left and right
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

		//if there are any leftovers from the left or right array, add to array as well
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
	};

	template<typename T>
	static void	mergeSort(T & array)
	{
		//find size of array
		size_t arraySize = array.size();

		//base case
		if (array.size() < 2)
			return ;

		//get the middle index of array. Don't forget that if array has odd number elements, left side is smaller
		size_t mid = arraySize / 2;

		//divide up array into left and right array
		//we can technically do left[i] = array[i], but then we would need to initialize left and right deque with a size
		T left; 
		T right;
		size_t i = 0;
		for (; i < mid; i++)
			left.push_back(array[i]);
		for (; i < arraySize; i++)
			right.push_back(array[i]);

		//recursively divide up the left and right arrays
		mergeSort(left);
		mergeSort(right);
		merge(left, right, array);
	};

	/* --------------------------------------------------------------------------- */
	//iterator version to work with lists as well
	template<typename T>
	static void	merge(T & left, T & right, T & array)
	{
		typename T::iterator leftIT = left.begin();
		typename T::iterator rightIT = right.begin();
		typename T::iterator arrayIT = array.begin();
		

		while (leftIT != left.end() && rightIT != right.end())
		{
			if (*leftIT <= *rightIT)
			{
				//DON'T USE INSERT - we need to replace the element
				// array.insert(arrayIT, *leftIT);
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

		//if there are any leftovers from the left or right array, add to array as well
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
	};

	template<typename T>
	static void	mergeSort(T & array)
	{
		size_t arraySize = array.size();

		if (array.size() < 2)
			return ;
		size_t mid = arraySize / 2;
		typename T::iterator arrayIT = array.begin();
		
		//left.push_back(*(arrayIT + i)); ->iterators don't support direct addition;
		T left;
		T right;
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
		mergeSort(left);
		mergeSort(right);
		merge(left, right, array);
	};

	template<typename T>
	static void	printArray(T array)
	{
		for (typename T::iterator it = array.begin(); it != array.end(); it++)
			std::cout << "(" << it->first << "," << it->second << ") ";
		std::cout << "\n";
	};

	// static typename T::iterator ftLowerBound(typename T::iterator beginIT, typename T::iterator endIT, int numToFind)
	// this doesn't work for some reason but the below does
	template<typename Iterator>
	static Iterator ftLowerBound(Iterator beginIT, Iterator endIT, int numToFind)
	{
		// if there is only one element, return iterator
		if (beginIT == endIT)
			return (beginIT);

		//size of std::distance can be negative in bidirectional or ranandom access containers
		//find size of array between two inputed iterators and middle index
		int arraySize = std::distance(beginIT, endIT) + 1; 
		int mid = arraySize / 2;

		//if array has 2 elements, check number against both elements
		if (arraySize == 2)
		{
			if (*beginIT >= numToFind)
				return beginIT;
			else
				return endIT;
		}
		//save beginIT in oldBeginIT and convert begin to mid(move beginIT to middle)
		//if even sized array, move beginIT to one less than mid (end of left side);
		//if num == mid, return mid
		//if num < mid, search begin to mid (DON'T FORGET TO INCLUDE MID!) - 
			//this is bc we want to return the first number that is bigger than number, so mid might still be this number
		//if num > mid, search mid + 1 to end (DON'T NEED TO INCLUDE MID!)
		// typename T::iterator oldBeginIT = beginIT;
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
};

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