#pragma once

#include <list>
#include <vector>

class PmergeMe
{
private:
	static std::list<int>	_l;
	static std::vector<int>	_v;

	PmergMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();
	PmergeMe &	operator=(PmergeMe const & src);
public:
	static void	sortList();
	static void	sortVector();

	class InvalidInputException : public std::exception{
		const char *what() const throw(){return "Non numerical input detected";}
	};
};

/* NOTES:
-create two different containers - list and probably vector/deque
-populate containers with numbers from cmd line
-print out Before list

1. determine if array is even or odd. if odd, set last number as straggler. it will be last to be inserted
2. divide sequence to sort into pairs
3. sort each pair [less, greater]
4. sort sequence recursively by value of greater number in pair
5. Main Chain - creaete array of ordered greater number from each pair - insert into main chain
4. place less num of each pair into temporary pend array
5. insert the first number in front
6. build jacobsthal numbers based on number of insertions
7. use binary search to insert each pend  element into main chain
8. insert straggler if there

Don't forget to time the sorting in each container and print it out
*/