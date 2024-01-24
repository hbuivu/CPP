#pragma once

# include <deque>
# include <vector>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <utility>
# include <type_traits>

class PmergeMe
{
private:
	static std::deque<int>	_deck;
	static std::vector<int>	_vect;

	PmergeMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();
	PmergeMe &	operator=(PmergeMe const & src);

	static int Jacobsthal(int s);
public:
	static void	sortDeque();
	static void	sortVector();
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
		while (size > jacobNum)
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

	template<typename T>
	static void	sortPairs(T container)
	{
		
	}
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